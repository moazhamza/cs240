#include "AntHill.h"
#include "Ant.h"
#include <iostream>

using namespace std;


// AntHill implementation

/* AntHill constructor. Creates a fresh hill with no ants */
AntHill::AntHill(){
    current_ants = 0;
    next_id = 0;
}

/* AntHill destructor. Deletes all instances of ants in the hill and also
 * frees the array which held the ants
 */
AntHill::~AntHill(){
    delete listOfAnts;
}

/* Attempts to add an ant to the AntHill. Returns new ant's ant ID*/
int AntHill::addAnt(){
    Ant * newAnt = new Ant(next_id++);
    listOfAnts->addAnt(newAnt);
    current_ants++;
    return newAnt->getID();
}

/* Attempts to remove an ant. Returns false if the ID of the ant to be removed
 * was not found in the hill (ant linked List)
 */
bool AntHill::removeAnt(int id){
    if(listOfAnts->deleteAnt(id)){
        current_ants--;
        return true;
    }
    return false;
}

/* Returns a pointer to the ant with ant id antID */
Ant *AntHill::getAnt(int antID){
    Ant *returnAnt = NULL;
    listOfAnts->findAnt(antID);
    return returnAnt;
}

/* Moves all ants in AntHill a random direction */
void AntHill::move(){
    listOfAnts->move();
}

/* Prints the ID and location of each ant in the hill */
void AntHill::printHillInfo(){
    listOfAnts->printHillInfo();  
}
