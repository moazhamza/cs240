#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Ant.h"

class Node{
    public: 
        Node(Ant*);
        Ant *ant;
        Node *next;

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
        void move();

        void printHillInfo();
        void printList();


};
#endif
