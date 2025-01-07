#include <iostream>
#include "Node.hpp"

#include <string>


//Defining constructor
Node::Node(const std::string& w, int t){
    word = w;
    token = t;
    p_next = nullptr;  //next pointer not initially connected to any nodes

}

//Define Deconstructor
Node::~Node(){}


 //Defining getter methods for private data members
int Node::getToken() const{
    return token;
}
std::string Node::getWord() const{
    return word;
}
Node* Node::getNext() const {
    return p_next;
}


//setter methods
void Node::setToken(int t){
    token = t;
}

void Node::setWord(const std::string& w){
    word = w;
}

void Node::setNext(Node *next){
    p_next = next;
    
}

