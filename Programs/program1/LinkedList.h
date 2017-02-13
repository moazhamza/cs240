#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Ant.h"
#include <fstream>

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
        void move(int);

        int determineNumDefenders(int);
        void removeDefendingAnts(int);

        int fightOrFood(std::fstream&); 

        void printHillInfo();
        void printList();


};
#endif
