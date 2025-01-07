#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "TokenDictionary.hpp"
#include "HashTable.hpp"
#include "LinkedList.hpp"

#include <string>

class HashTable{

    private:
        TokenDictionary dict; //instance of token dictionary
        LinkedList* hashTable; //pointer to an array of linked lists 
        int hashTableSize; 
        


    public:
        //Constructor and deconstructor declaration
        HashTable(int size);
        ~HashTable();


        //Helper functions
        bool isAlphabetic(const std::string& word);
        int hashFunction(const std::string& word);



        //Member functions for all commands in the hash table while passing appropiate parameters as per project instructions 
        bool insert(const std::string& word);
        bool readFile(std::fstream& fin);
        int tokenize(const std::string& word);
        std::string retrieve(int t);
        std::string tokenizeString(const std::string& strOfWords); //STOK
        std::string convertTokentoWord(const std::string& strOfTokens); //TOKS
        std::string prtChain(int k);
      

};

#endif