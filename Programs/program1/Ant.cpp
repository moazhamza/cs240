#include "Ant.h"
#include <cstdlib>
#include <iostream>

#define INVALID_ID -1

#define RANDOM_DIRECTION 3
#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3

#define MAX_EXP 100

using namespace std;

/* Valid ant constructor which sets
 * position to (0,0) and sets its ID using the argument
 * Assigns random exp to ant
 */
Ant::Ant(int id){
    this->id = id;
    this->x = 0;
    this->y = 0;
    this->exp = (rand() % MAX_EXP)+1;
}

/*
 * Invalid Ant ID constructor
 */
Ant::Ant(){
    this->id = INVALID_ID;
    this->x = 0;
    this->y = 0;
    this->exp = 0;
}
/*
 * Copy constructor for Ant object
 */
Ant::Ant(const Ant &other){
    this->id = other.id;
    this->x = other.x;
    this->y = other.y;
    this->exp = other.exp;
}


/* Move the ant 1 unit in a random direction - NO GRID RESTRICTIONS
 */
void Ant::move(){
    /* finds a random direction to move using rand() and
     * changes the corressponding coordinate appropriately
     **/
    int directionToBeChanged = rand() % RANDOM_DIRECTION;
    if (directionToBeChanged == EAST) x++;
    else if (directionToBeChanged == WEST) x--;
    else if (directionToBeChanged == NORTH) y++;
    else if (directionToBeChanged == SOUTH) y--;
}

/*
 * Move ant with maximum grid
 */
void Ant::move(int max){
    int directionToBeChanged = rand() % RANDOM_DIRECTION;
    if ((directionToBeChanged == EAST) && (x+1 < max)) x++;
    else if ((directionToBeChanged == WEST) && (x-1 >= 0)) x--;
    else if ((directionToBeChanged == NORTH) && (y+1 < max)) y++;
    else if ((directionToBeChanged == SOUTH) && (y-1 >= 0)) y--;
}

/* Allows another Ant object to challenge this ant object
 * to a fight.
 *
 * The outcome of the fight is based on the exp value of each ant
 *
 * A random number from 1 to the exp of the corresponding ant is assigned
 * as the score of that ant
 *
 * The ant with the higher score wins and gains the experience of the losing ant
 */
bool Ant::fight(Ant * otherAnt){
    int myEXP = this->getEXP();
    int otherEXP = otherAnt->getEXP();
    int myScore = rand() % myEXP;
    int otherScore = rand() % otherEXP;
    
    if(myScore >= otherScore){
        this->setEXP(myEXP + otherEXP);
        return true;
    }
    else{
        otherAnt->setEXP(myEXP + otherEXP);
        return false;
    }
}
