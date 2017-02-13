#include "LinkedList.h"

#include <iostream>

#define HALF 0.5
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

int List::determineNumDefenders(int gridSize){
    Node *curr = head;
    int numDefenders = 0;
    while(curr != 0){
        Ant anAnt = *(curr->ant);
        if(anAnt.getX() < HALF*gridSize && anAnt.getY() < HALF*gridSize) numDefenders++;
    }
    return numDefenders;
}

void List::removeDefendingAnts(int gridSize){
    Node *curr = head;
    while(curr != 0){
        Ant anAnt = *(curr->ant);
        if(anAnt.getX() < HALF*gridSize && anAnt.getY() < HALF*gridSize) this->deleteAnt(anAnt.getID());
    }
}

int List::fightOrFood(fstream& file){
    Node *curr = head;
    int foodToAdd = 0;
    while(curr != 0){
        Ant anAnt = *(curr->ant);
        if(rand() % 5 == 0){
           file << "Ant #" << anAnt.getID() << " has run into a rival ant" << std::endl;
           Ant *rivalAnt = new Ant(-1);
           Ant *winner = anAnt.fight(rivalAnt);
           if(winner->getID() != anAnt.getID()){
               file << "Ant #" << anAnt.getID() << "loses the fight and dies" << std::endl;
               this->deleteAnt(winner->getID());
               
           }
           delete rivalAnt;
        }
        else if(rand() % 5 == 0){
            file << "Ant #" << anAnt.getID()  << " has found food!" << std::endl;
            foodToAdd++;   
        }
    }   
    return foodToAdd;
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


