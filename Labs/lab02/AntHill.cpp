#include "AntHill.h"
#include <iostream>
#include <cstdlib>

using namespace std;
//Ant implementation

Ant::Ant(){
    x = 0;
    y = 0;
    id = -1;
}

Ant::Ant(int ID){
    x = 0;
    y = 0;
    id = ID;
}
void Ant::move(){
    int directionToBeChanged = rand() % 3;
    if (directionToBeChanged == 0) x++;
    else if (directionToBeChanged == 1) x--;
    else if (directionToBeChanged == 2) y++;
    else y--;
}

int Ant::getID(){
    return id;
}

int Ant::getX(){
    return x;
}

int Ant::getY(){
    return y;
}


// AntHill implementation

AntHill::AntHill(int max){
    current_ants = 0;
    max_ants = max;

}

bool AntHill::addAnt(){
    if (next_id < max_ants){
        Ant newAnt(next_id);
        ants[next_id] = newAnt;
        next_id++;
        current_ants++;
        return true;
    }
    else return false;
}

Ant AntHill::getAnt(int antID){
    return ants[antID];
}

void AntHill::move(){
    for (Ant ant : ants) ant.move();
}

bool AntHill::changeMax(int max){
    if (max > 0 && max < 100){
        max_ants = max;
        return true;
    }
    else{
        return false;
    }
}

void AntHill::printHillInfo(){
    for (Ant a : ants){
        cout << "Ant #" << a.getID() << "[" << a.getX() << "," << a.getY() << "]" << endl;
    }
}

int AntHill::getCurrentNumAnts(){
    return current_ants;
}
int AntHill::getMaxAnts(){
    return max_ants;
}














