#include "AntHill.h"
#include "Ant.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


// AntHill implementation

/* AntHill constructor. Creates a fresh hill with no ants */
AntHill::AntHill(){
    current_ants = 3;
    next_id = 3;
    food = 0;
    gridSize = 25; 
    numAttacks = 0;
    losses = 0;
    for(int i=0;i<3;i++) listOfAnts->addAnt(new Ant(i));
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
    listOfAnts->move(gridSize);
}

/* Prints the ID and location of each ant in the hill */
void AntHill::printHillInfo(){
    listOfAnts->printHillInfo();  
}

void AntHill::attack(){
   bool attack = rand() % 5 == 0;
   if (attack){
        numAttacks++;
        int numDefenders = listOfAnts->determineNumDefenders(this->gridSize);
        int numAttackers = rand() % current_ants;
        cerr << "numDefenders = " << numDefenders << "vs. " << numAttacks << endl;
        if (numDefenders > numAttackers) return;
        else{
            listOfAnts->removeDefendingAnts(gridSize);
            losses++;
        }
   }
}

void AntHill::fightOrFood(fstream& logFile){
    this->food += listOfAnts->fightOrFood(logFile);
}

void AntHill::outputHillStatus(fstream& file){
    file << "The hill currently has:\
             \n\tFood: " << food
             << "\n\tAnts: " << current_ants << endl;
    file << "The hill has been attacked " << numAttacks << " times. \
                \n\t Successfully defended: " << numAttacks - losses << "\
                \n\t Failed to Defend: " << losses << endl;
}

void AntHill::turn(){
    fstream logFile;
    logFile.open("anthill.log", ios::app);

    logFile << "------------- New AntFarm Simulation --------------" << endl;
    this->outputHillStatus(logFile); 

    while(food > 0) {
        addAnt();
        food--;
    }

    this->move();
    this->attack();
    this->fightOrFood(logFile);

    logFile.close();
}
