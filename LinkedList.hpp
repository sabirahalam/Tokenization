#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include <string>

class LinkedList{

    private:
        Node *p_head; //pointer for the head node of the linked list

    public:
        //Constructor and deconstructor declaration
        LinkedList();
        ~LinkedList();
        
        //Member function
        bool insertNewNode(const std::string& word, int token); //insert node in list
        int index(const std::string& word); //retrieve token of word
        int getKey(const std::string& word); //calculate sum of ascii char
        std::string printChain(); //prints chain of keys 
};

#endif