#ifndef TOKEN_DICTIONARY_HPP
#define TOKEN_DICTIONARY_HPP

#include <string>

class TokenDictionary {
private:
    std::string* words; //dynamic array to store words
    int capacity;  //current capacity of the dynamic array
    int size;  //# of words stored in array

    

public:
    //Constructor and deconstructor declarations 
    TokenDictionary();
    ~TokenDictionary();

    //helper function to double the capacity of the dyamic array
    void resize();
   
    int addWord(const std::string& word); //add words to array
    std::string getWord(int token) const; //retrieve word based on token

    //getter function 
    int getSize() const;
};

#endif 
