#include "AntHill.h"
#include "Ant.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#define RIVAL_ANT_ID 999999999
#define HALF 0.5

#define GRID_SIZE 25
#define INIT_NUM_ANTS 3
#define MAX_ANTS 100

#define INVALID_ID -1

#define CHANCE_FIGHT 5
#define CHANCE_FOOD 5
#define CHANCE_ATTACK 5

// AntHill implementation

/* AntHill constructor. Creates a fresh hill with inital number of ants */
AntHill::AntHill(){
    current_ants = INIT_NUM_ANTS;
    next_id = INIT_NUM_ANTS;
    food = 0;
    grid_size = GRID_SIZE;
    num_attacks = 0;
    losses = 0;
    for(int i=0;i<INIT_NUM_ANTS;i++) listOfAnts->addAnt(new Ant(i));
}

/* AntHill destructor. Deletes all instances of ants in the hill and also
 * frees the array which held the ants
 */
AntHill::~AntHill(){
    delete listOfAnts;
    this->logfile.close();
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
    listOfAnts->move(grid_size);
}

/* Prints the ID and location of each ant in the hill */
void AntHill::printHillInfo(){
    listOfAnts->printHillInfo();
}


/*
 * Determines how many ants are within half the grid
 * size in order to determine how many defending ants
 */
int AntHill::determineNumDefenders(){
    int numDefenders = 0;
    for(listOfAnts->setCurrToHead(); listOfAnts->curr; listOfAnts->advanceCurr()){       Ant anAnt = *(listOfAnts->curr->ant);
        if(anAnt.getX() < HALF*grid_size && anAnt.getY() < HALF*grid_size) numDefenders++;
    }
    return numDefenders;
}

/*
 * Removes the ants which are within half the grid size 
 * (defending ants)
 */
void AntHill::removeDefendingAnts(){
    int deadAnts[100] = {-1};
    int antsToDelete=0;
    for(listOfAnts->setCurrToHead(); listOfAnts->curr; listOfAnts->advanceCurr()){
        Ant anAnt = *(listOfAnts->curr->ant);
        if(anAnt.getX() < HALF*grid_size && anAnt.getY() < HALF*grid_size){
            deadAnts[antsToDelete] = anAnt.getID();
            antsToDelete++;
        }
    }
    
    for(int i = 0; i < antsToDelete; i++){
        removeAnt(deadAnts[i]);
    }
}

/*
 * Run random chance simulation of whether ants were 
 * attacked. If it was, determine the number of defenders
 * to defend and assign a random number to the attackers
 * Remove the defending ants and food if they lose
 */
void AntHill::attack(fstream &logfile){
    if (rand() % CHANCE_ATTACK == 0){
        logfile << "The hill has been attacked!" << endl;
        num_attacks++;
        int numDefenders = determineNumDefenders();
        int numAttackers = rand() % current_ants + 1;
        logfile << "Defenders = " << numDefenders << " vs. " << numAttackers << endl;
        if (numDefenders > numAttackers) {
            logfile << "The ants successfully fend off the attack." << endl;
        }
        else{
            logfile << "The ants did not fend off the attack. All defending ants died and all the food was stolen" << endl;
            removeDefendingAnts();
            food = 0;
            losses++;
        }
    }
}

/*
 * Determine whether each ants fight or find food
 * Add food and delete losing ants
 */
void AntHill::fightOrFood(fstream &logfile){
    int numAntsToDelete = 0;
    int deadAnts[MAX_ANTS] = {INVALID_ID};
    for(listOfAnts->setCurrToHead(); listOfAnts->curr != NULL; listOfAnts->advanceCurr()){
        Ant *myAnt = listOfAnts->curr->ant;
        if(rand() % CHANCE_FIGHT == 0){
            logfile << "Ant #" << myAnt->getID() << " has run into a rival ant" << std::endl;
            
            Ant rivalAnt(RIVAL_ANT_ID);
            if(rivalAnt.fight(myAnt)){
                logfile << "Ant #" << myAnt->getID() << " loses the fight and dies" << std::endl;
                deadAnts[numAntsToDelete] = myAnt->getID();
                numAntsToDelete++;
            }
            else{
                logfile << "Ant #" << myAnt->getID() << " won the fight" << std::endl;
            }
        }
        else if(rand() % CHANCE_FOOD == 0){
            logfile << "Ant #" << myAnt->getID()  << " has found food!" << std::endl;
            food++;
        }
    }
    for (int i=0; i < numAntsToDelete; i++){
        removeAnt(deadAnts[i]);
    }
}

/* 
 * Print to file the number of ants and the amount of
 * times the hill has been attacked
 */
void AntHill::outputHillStatus(fstream &logfile){
   
    logfile << "The hill currently has:\
    \n\tFood: " << food
    << "\n\tAnts: " << current_ants << endl;
    
    logfile << "The hill has been attacked " << num_attacks << " times. \
    \n\t Successfully defended: " << num_attacks - losses << "\
    \n\t Failed to Defend: " << losses << endl;
    
}

/*
 * Run a turn in the simulation
 */
void AntHill::turn(){
	fstream logfile;
    logfile.open("anthill.log", ios::app);

    this->outputHillStatus(logfile);
    
    while(food > 0) {
        addAnt();
        food--;
    }
    
    this->move();
    this->fightOrFood(logfile);
    if(current_ants > 0) this->attack(logfile);
    
    this->outputHillStatus(logfile);
    
}
