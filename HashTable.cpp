#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"
#include "HashTable.hpp"
#include "TokenDictionary.hpp"


//Defining Constructor (creates new hash table)
HashTable::HashTable(int m) {
    hashTableSize = m; 
    hashTable = new LinkedList[m]; //each linkedlist default constructor is called here
    
}


//Defining Deconstructor
HashTable::~HashTable(){
    delete [] hashTable;
}
    
//** HELPER FUNCTIONS **//

//Function determines if a word contains alphabetic characters
bool HashTable::isAlphabetic(const std::string& word) {
    for(size_t i=0; i < word.length(); i++){
        char c = word[i];
        //if any char is not an uppercase or lowercase 
        if(!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }
    return true; //if all characters are alphabets :)
}

//Function performs the hashing 
int HashTable::hashFunction(const std::string& word) {
    int key = 0;
    //iterates through each character of the word 
    for(size_t i=0; i < word.length(); i++){
        //sums all the characters 
        key += word[i]; //compiler implicity converts to ASCII value when char treated as type int
    }
    return key % hashTableSize; 
}



//** MEMBER FUNCTIONS **//

//Inserts a new word into the hash table
bool HashTable::insert(const std::string& word) {
    //Checks if the word has alphabetic char
    if (!isAlphabetic(word)) {
        return false;
    }

    int key = hashFunction(word); //creates hash key
    int token = dict.addWord(word); //Add word to dictionary and get token 

    //check if word already in the hash table
    if (token == -1 || hashTable[key].index(word) != -1) {
        return false; //word already present
    }

    //insert new word and its token in correct position of hash table
    hashTable[key].insertNewNode(word, token);
    return true;
}


//Retrieves token for a word
int HashTable::tokenize(const std::string& word) {
    //Genererate hash key
    int key = hashFunction(word);
    int token = hashTable[key].index(word); //retrieve token from appropiate bucket 

    //If the word is found, return t
    if (token != -1) {
            return token;
    } else {
            return 0;
        }
}


//Retrieves word based on token 
std::string HashTable::retrieve(int token) {
    return dict.getWord(token); //return word associated with token from dictionary
}


//Reads words from a file
bool HashTable::readFile(std::fstream& fin) {
    bool addWord = false;
    std::string word;

    //read word from file one by one 
    while(fin >> word) {
        if (isAlphabetic(word) && insert(word)) { //check if word is alphabetic and successfully inserted
            addWord = true;
        }
    }
    return addWord; //if at least one word added (true)
}



//Tokenize all words in a string 
std::string HashTable::tokenizeString(const std::string& strOfWords) {
    std::string tokenResult = ""; //stores token for each word in string
    std::string word = ""; //accumulates the characters of words in the string

    //iterate through each char of the string
    for (size_t i=0; i < strOfWords.length(); i++) {
        
        //keep building the word if character is not a space
        if(strOfWords[i] != ' ') {
            word += strOfWords[i];
        }

        //If it's the end of a word (either a space or the last char of a string)
        if (strOfWords[i] == ' ' || i == strOfWords.length() - 1) {
            //if complete word is formed 
            if (!word.empty()) {
                
                int token = tokenize(word); //convert word to associated token

                //If the word is "_DONE_" break out of the loop
                if (word == "_DONE_") {
                    break;
                }
                tokenResult += std::to_string(token) + " "; //convert token to string and add it to the string of tokens 
                word = ""; //reset word to empty to get the next word in the string
            }
        }
    }
    return tokenResult;
}




//Turn string of tokens into string of words 
std::string HashTable::convertTokentoWord(const std::string& strOfTokens) {
    std::string wordResult = "";  //stores words for each token in a string 
    std::string token = ""; //accumulates each token as we iterate through the string

    //iterate through each char of the string
    for (size_t i = 0; i < strOfTokens.length(); i++) {
        if (strOfTokens[i] == ' ' || i == strOfTokens.length() - 1) {
            if (i == strOfTokens.length() - 1) {
                token += strOfTokens[i];
            }

            //if token not -1, process token otherwise stop processing
            if(token != "-1") { 
                int tokenValue;
                
                try {
                    tokenValue = std::stoi(token);//convert token from string to integer
                    std::string word = retrieve(tokenValue); //retrieve word corresponding to token from dictionary
                    
                    //Perform a check for if word is found
                    if (word == "Not found") {
                        wordResult += "UNKNOWN ";
                    } 
                    else {
                        
                        wordResult += word + " ";
                    }
                } 
                
                /*
                    CITATION:

                    I was recieving an error message: "libc++abi: terminating due to uncaught exception 
                    of type std::invalid_argument: stoi: no conversion", while attempting
                    to convert a non-numeric string to an integer, advised by chat.openai.com 
                    with the prompt: "My code is throwing me [insert error message], how can I fix this error?"

                    The AI tool advised me with multiple solutions like checking for empty string before conversion,
                    and validating string before conversion, but after careful consideration and testing my program
                    with different edge cases I decided to catch the exception in case of a conversion error
                */

                //Catching a conversion error 
                catch(const std::invalid_argument& e) {
                    wordResult += "UNKNOWN "; 
                }
                token = "";
            } 
            else {
                break; 
            }
        } 
        else {
            token += strOfTokens[i];
        }
    }
    return wordResult;
}


//Prints chain of keys at position k in hash table 
std::string HashTable::prtChain(int k) {
    
    LinkedList& chain = hashTable[k]; //reference to linked list at specific index
    return chain.printChain(); //returns string of keys 
}


