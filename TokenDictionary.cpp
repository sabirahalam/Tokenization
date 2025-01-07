#include "TokenDictionary.hpp"


//Defining Constructor
TokenDictionary::TokenDictionary() {
    words = nullptr;  
    capacity = 0;    
    size = 0;         
}

//Defining Deconstructor 
TokenDictionary::~TokenDictionary() {
    delete[] words;
}

//Resize internal storage array
void TokenDictionary::resize() {
    //initially if size is zero, allocate space 1 word
    if (capacity == 0) {
        capacity = 1;
        words = new std::string[capacity];
        return;
    }

    //otherwise, double the capacity
    int newCapacity = capacity * 2;
    std::string* newWords = new std::string[newCapacity];

    //copy words from old array to new array
    for (int i = 0; i < size; i++) {
        newWords[i] = words[i]; 
    }

    //cleanup
    delete[] words;
    words = newWords;
    capacity = newCapacity;
}


//Adds words to dictionary
int TokenDictionary::addWord(const std::string& word) {
    //Checks for duplicates of a word in the dictionary
    for (int i = 0; i < size; i++) {
        if (words[i] == word) {
            return i + 1;  //return the existing token for this word
        }
    }
    //If array is full, resize before adding new word
    if (size == capacity) {
        resize();
    }
    words[size] = word;
    size++;
    return size;
}

//Retrieves word based on corresponding token
std::string TokenDictionary::getWord(int token) const {
    //Validate the token if it is within storage bounds of the array
    if (token > 0 && token <= size) {
        return words[token - 1]; //return word based on token 
    }
    return "Not found";
}

//Gets current size of dictionary 
int TokenDictionary::getSize() const {
    return size; //returns # of words in dictionary
}
