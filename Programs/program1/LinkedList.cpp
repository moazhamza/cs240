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
		delete curr;
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
    Node *current = this->head;
    Node *last = 0;
    if (current == 0) return false;
    while(current->ant->getID() != antID){
        last = current;
        current = current->next;
        if (current == 0){
            curr = head;
            return false;
        }
    }
    this->curr = head;
    if (current == this->head){
        this->head = current->next;
    }
    if (last != 0){
        last->next = current->next;
    }
	delete current->ant;
	delete current;
    
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

void List::move(int grid_size){
    Node *curr = this->head;
    while(curr != 0){
        curr->ant->move(grid_size);
        curr = curr->next;
    }
    
}

void List::setCurrToHead(){
    curr = head;
}

void List::advanceCurr(){
    curr = curr->next;
}

void List::operator<<(Ant *newAnt){
    this->addAnt(newAnt);
}

void List::printHillInfo(){
    Node *curr = this->head;
    while(curr != 0){
        std::cout << "Ant #" << curr->ant->getID() << " [" << curr->ant->getX() << "," << curr->ant->getY() << "]" << std::endl;
        curr = curr->next;
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

