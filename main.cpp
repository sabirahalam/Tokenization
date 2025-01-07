#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "TokenDictionary.hpp"
#include "HashTable.hpp"
#include <string>
#include <fstream>

#include <iostream>
#include <fstream>
#include "HashTable.hpp"

int main() {
    HashTable* hashTable = nullptr; //pointer for hash table instance
    std::string command; //storing user input for commands


    while (std::cin >> command) {
        //Create a new hash table
        if (command == "M") {
            int m;
            std::cin >> m;
            hashTable = new HashTable(m);
            std::cout << "success" << std::endl;
        } 
        
        //Insert a new word into the hash table
        else if (command == "INSERT") {
            std::string word;
            std::cin >> word;
            if (hashTable->insert(word)) {
                std::cout << "success" << std::endl;
            } else {
                std::cout << "failure" << std::endl;
            }
        } 
        
        //Read words from a file and insert into hash table
        else if (command == "READ") {
             if (!hashTable) {
                std::cout << "Hash table not initialized." << std::endl;
                continue;
            }

            std::string filename;
            std::cin >> filename;
            std::ifstream file(filename);
            std::string word;
            bool added = false; //checks if at least single word has been added

            while (file >> word) {
                if (hashTable->insert(word)) {
                    added = true;
                }
            }
            file.close();

            if (added) {
                std::cout << "success" << std::endl;
            } 
            else {
                std::cout << "failure" << std::endl;
            }
        } 
        
        //Retrive token for speciifc word
        else if (command == "TOKENIZE") {
            std::string word;
            std::cin >> word;
            int token = hashTable->tokenize(word);
            if (token == 0) {
                std::cout << "0" << std::endl;
            } else {
                std::cout << token << std::endl;
            }
        } 
        
        //Retrieve word based on token 
        else if (command == "RETRIEVE") {
            int t;
            std::cin >> t;
            std::string word = hashTable->retrieve(t);
            if (word == "Not found") {
                std::cout << "UNKNOWN" << std::endl;
            } else {
                std::cout << word << std::endl;
            }
        } 
        

        //Convert string of words into tokens 
        else if (command == "STOK") {
            std::string strOfWords, word;
            while (std::cin >> word && word != "_DONE_") {
                strOfWords += word + " ";
            }
            std::cout << hashTable->tokenizeString(strOfWords) << std::endl;
        } 
        
        //Convert string of tokens in to words
        else if (command == "TOKS") {
            std::string strOfTokens, token;
            while (std::cin >> token && token != "-1") {
                strOfTokens += token + " ";
            }
            std::cout << hashTable->convertTokentoWord(strOfTokens) << std::endl;


        //Print chain of keys 
        } else if (command == "PRINT") {
            int k;
            std::cin >> k;
            std::cout << hashTable->prtChain(k) << std::endl;
        
        
        //Exit program
        } else if (command == "EXIT") {
            delete hashTable;
            return 0;
        } 
    }

    delete hashTable;
    return 0;
}
