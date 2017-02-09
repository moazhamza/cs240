#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Ant.h"

class Node{
    private: 
        Ant *data;
        Node *next;
    public:
        Node(Ant*);
        Node *getNextNode(){return next;}
        void setNextNode(Node * n){this->next = n;}
        Ant *getAntPtr(){return data;}
};

class List{
    private:
        Node *head;
        Node *findLastNode();
    public:
        List();
        List(const List&);
        ~List();
       
        void addAnt(Ant*);
        void operator<<(Ant*);
        bool deleteAnt(int);
        Ant *findAnt(int);

        void printList();


};
#endif
