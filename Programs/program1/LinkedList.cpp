#include "LinkedList.h"

#include <iostream>

// Node implementation 
     
Node::Node(Ant* ant){
    this->ant = ant;
    this->next = 0;
}

// List implementation

List::List(){
    this->head = 0;
}

List::List(const List &other){
    this->head = other.head;
}

List::~List(){
    Node *curr = head;
    while(curr != 0){
        delete curr->ant;
        curr = curr->next;
    }
}

Node *List::findLastNode(){ 
    Node *curr = this->head;
    while(curr->next != 0){
        curr = curr->next;
    }
    return curr;
}

void List::addAnt(Ant* newAnt){
    Node *newNode = new Node(newAnt);
    if (this->head == 0) this->head = newNode;
    else{
        Node *lastNode = this->findLastNode();
        lastNode->next = newNode;
    }
}


bool List::deleteAnt(int antID){
    Node *curr = this->head;
    Node *last = 0;
    if (curr == 0) return false;
    while(curr->ant->getID() != antID){
        last = curr;
        curr = curr->next;
        if (curr == 0) return false;
    }
    last->next = curr->next;
    curr->next = 0;
    return true;

}
Ant *List::findAnt(int antID){
    Node *curr = this->head;
    if (curr == 0) return 0;
    while(curr->ant->getID() != antID){
        curr = curr->next;
        if (curr == 0) return 0;
    }
    return curr->ant;
}

void List::move(int gridSize){
    Node *curr = this->head;
    while(curr != 0){
        curr->ant->move(gridSize);
        curr = curr->next;
    }

}

void List::operator<<(Ant *newAnt){
    this->addAnt(newAnt);
}

void List::printHillInfo(){
    Node *curr = this->head;
    while(curr != 0){
        std::cout << "Ant #" << curr->ant->getID() << " [" << curr->ant->getX() << "," << curr->ant->getY() << "]" << std::endl;
    }
}
void List::printList(){
    Node *curr = this->head;
    if (curr == 0){
        std::cerr << "This is an empty list" << std::endl;
        return;
    }

    while(curr->next !=  0){
        std::cerr << curr->ant->getID() << "-->";
        curr = curr->next;
    }

    std::cerr << curr->ant->getID() << "--> 0" << std::endl;
}


