#include <iostream>
#include "LinkedList.hpp"

//Defining Constructor
LinkedList::LinkedList(){
    p_head = nullptr;
}

//Defining Deconstructor
LinkedList::~LinkedList(){
    //Initialize current pointer to head/beginning of linked list
    Node* current = p_head;

    //traverse through linked list as long as current points to valid node
    while (current){

        //get the next node by calling appropiate getter member function 
        Node* next = current->getNext(); //also created next pointer to store next value before deleting current node
        delete current;
        current = next;
    }
}

//prepend new node in the linked list (beginning of the list)
 bool LinkedList::insertNewNode(const std::string& word, int token) {
    Node* newNode = new Node(word, token);

    //if list is empty, set new node as head
    if (!p_head) {
        p_head = newNode;
        return true;
    }

    Node* current = p_head;

    //check if word already exists to avoid duplicates
    while (current) {
        if (current->getWord() == word) {
            delete newNode; // If already in the list delete the newly created node
            return false;
        }
        //if we reached the end of list, insert new node in LL
        if (!current->getNext()) {
            current->setNext(newNode);
            return true;
        }
        current = current->getNext();
    }
    return false;
}



//retrieves token of corresponding word 
int LinkedList::index(const std::string& word) {
    Node* current = p_head;

    //Traverse through linked list until current node matches searched word
    while(current) {
        if(current->getWord() == word) { 
            return current->getToken();//return token(index)
        }
        current = current->getNext();
    }
    return -1; //token not found
}


//Calculates sum of ASCII characters in word
int LinkedList::getKey(const std::string& word) {
    int key = 0;
    for(size_t i = 0; i < word.length(); i++) {
        key += word[i];
    }
    return key;
}

//Chain of keys in linkedlist
std::string LinkedList::printChain() {
    //Check if linkedlist is empty
    if (!p_head) {
        return "chain is empty";
    }

    //get key from previous function for corresponding word and convert to string
    int key = getKey(p_head->getWord());
    std::string result = std::to_string(key); 
    Node* current = p_head->getNext();

    //Traverse remaining linked list to add key to string of keys
    while (current) {
        key = getKey(current->getWord());
        result += " " + std::to_string(key);
        current = current->getNext();
    }
    return result;
}





