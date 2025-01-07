#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node{


    private:
        int token; //index assigned to each word
        std::string word; //word being stored in the node
        Node *p_next; //pointer to get next node in the list

    
    public:
        //Constructor and deconstructor declaration
        Node(const std::string& w, int t);
        ~Node();

        //Declaring getter/setter memeber functions 
        int getToken() const;
        std::string getWord() const;
        Node* getNext() const;

        void setToken(int t);
        void setWord(const std::string& w);
        void setNext(Node *next);


           
};

#endif