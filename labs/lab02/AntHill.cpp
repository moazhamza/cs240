#include "AntHill.h"
#include <iostream>
#include <cstdlib>

#define INVALID_ID -1

#define RANDOM_DIRECTION 3 
#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3

#define TOTAL_MAX 100
using namespace std;


//Ant implementation

/* Invalid ant constructor */
Ant::Ant(){
    x = 0;
    y = 0;
    id = INVALID_ID;
}

/* Valid ant constructor which sets position to (0,0) and sets its ID using the argument */
Ant::Ant(int id){
    x = 0;
    y = 0;
    this->id = id;
}

/* Move the ant 1 unit in a random direction */
void Ant::move(){
    /* finds a random direction to move using rand() and 
     * changes the corressponding coordinate appropriately
     */
    int directionToBeChanged = rand() % RANDOM_DIRECTION;
    if (directionToBeChanged == EAST) x++;
    else if (directionToBeChanged == WEST) x--;
    else if (directionToBeChanged == NORTH) y++;
    else if (directionToBeChanged == SOUTH) y--;
}

/* Returns the Ant's ID number */
int Ant::getID(){
    return id;
}

/* Returns ant's x position */
int Ant::getX(){
    return x;
}

/* Returns ant's y position */
int Ant::getY(){
    return y;
}


// AntHill implementation

/* AntHill constructor, sets max ants */
AntHill::AntHill(int max){
    current_ants = 0;
    next_id = 0;
    max_ants = max;

}

/* Attempts to add an ant. Returns true if successful */
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

/* Returns copy of ant with ant id antID */
Ant AntHill::getAnt(int antID){
    return ants[antID];
}

/* Moves all ants in AntHill a random direction */
void AntHill::move(){
    for (int i=0; i < current_ants; i++) ants[i].move();
}

/* Change maximum capacity of AntHill object */
bool AntHill::changeMax(int max){
    if (max > 0 && max < TOTAL_MAX){
        max_ants = max;
        return true;
    }
    else{
        return false;
    }
}

/* Prints the ID and location of each ant in the hill */
void AntHill::printHillInfo(){
    for (int i=0; i < current_ants; i++){
        cout << "Ant #" << ants[i].getID() << "[" << ants[i].getX() << "," << ants[i].getY() << "]" << endl;
    }
}

/* Getter for current_ants */
int AntHill::getCurrentNumAnts(){
    return current_ants;
}

/* Getter for max_ants */
int AntHill::getMaxAnts(){
    return max_ants;
}




