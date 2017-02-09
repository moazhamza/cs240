#include "LinkedList.h"

#include <iostream>

// Node implementation 
     
Node::Node(Ant* ant){
    this->data = ant;
    this->next = 0;
}

// List implementation

List::List(){
    this->head = 0;
}

List::List(const List &other){
    this->head = other.head;
}

List::~List(){}

Node *List::findLastNode(){ 
    Node *curr = this->head;
    while(curr->getNextNode() != 0){
        curr = curr->getNextNode();
    }
    return curr;
}

void List::addElement(Ant* newAnt){
    Node *newNode = new Node(newAnt);
    if (this->head == 0) this->head = newNode;
    else{
        Node *lastNode = this->findLastNode();
        lastNode->setNextNode(newNode);
    }
}


bool List::deleteElement(int antID){
    Node *curr = this->head;
    Node *last = 0;
    while(curr->getAntPtr()->getID() != antID){
        last = curr;
        curr = curr->getNextNode();
        if (curr == 0) return false;
    }
    last->setNextNode(curr->getNextNode());
    curr->setNextNode(0);
    return true;

}

void List::operator<<(Ant *newAnt){
    this->addElement(newAnt);
}

void List::printList(){
    Node *curr = this->head;
    while(curr->getNextNode() !=  0){
        std::cerr << curr->getAntPtr()->getID() << "-->" << std::endl;
        curr = curr->getNextNode();
    }

    std::cerr << curr->getAntPtr()->getID() << "--> 0" << std::endl;
}

