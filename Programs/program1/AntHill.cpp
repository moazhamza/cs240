#include "AntHill.h"
#include "Ant.h"
#include <iostream>

using namespace std;


// AntHill implementation

/* AntHill constructor. Creates a fresh hill with no ants */
AntHill::AntHill(){
    current_ants = 0;
    next_id = 0;
    this->ants = NULL;
}

/* AntHill destructor. Deletes all instances of ants in the hill and also
 * frees the array which held the ants
 */
AntHill::~AntHill(){
    for(int i=0; i < current_ants; i++){
        delete ants[i];
    }    
    delete ants;
}

/* Attempts to add an ant to the AntHill. Returns new ant's ant ID*/
int AntHill::addAnt(){
    Ant **newArray = new Ant*[1+current_ants];
    // A new array is made and all the ant pointers from the old array are copied over
    for(int i=0; i < current_ants; i++){
        newArray[i] = ants[i];
    }
    // Add the new ant to the end of the array
    Ant *newAnt = new Ant(next_id);
    newArray[current_ants] = newAnt;

    current_ants++;
    next_id++;
    
    // Delete the old array and set the ants array to the new array created 
    // with the new ant
    delete ants;

    ants = newArray;  
    
    return newAnt->getID();
}

/* Attempts to remove an ant. Returns false if the ID of the ant to be removed
 * was not found in the hill (ant array)
 */
bool AntHill::removeAnt(int id){
    bool success = false;
    Ant *antToBeRemoved = getAnt(id);
    // Check if the ant with id exists. If it doesn't, return false
    if(antToBeRemoved){
        // Create a new array which holds one less than the number of ants
        // originally in the array
        Ant **newArray = new Ant*[current_ants-1];
        bool antWasRemoved = false;
        // Go through the old array and add the ants to the new array
        // When you find the ant that needs to be removed, remove it.
        // and then from now on set correct index in the new array.
        for(int i=0; i < current_ants; i++){
            if(antWasRemoved){
                newArray[i-1] = ants[i];
            }
            else{
                if(ants[i] != antToBeRemoved){
                    newArray[i] = ants[i];
                }
                else{       
                    delete antToBeRemoved;
                    antWasRemoved = true;
                }   
            }
        }
        current_ants--;
        delete ants;
        ants = newArray;
        success  = true;
    }
    return success;
}

/* Returns a pointer to the ant with ant id antID */
Ant *AntHill::getAnt(int antID){
    Ant *returnAnt = NULL;
    for(int i=0; i < current_ants; i++){
        if(ants[i]->getID() == antID) returnAnt = ants[i];
    }
    return returnAnt;
}

/* Moves all ants in AntHill a random direction */
void AntHill::move(){
    for (int i=0; i < current_ants; i++) ants[i]->move();
}

/* Prints the ID and location of each ant in the hill */
void AntHill::printHillInfo(){
    for (int i=0; i < current_ants; i++){
        cout << "Ant #" << ants[i]->getID() << "[" << ants[i]->getX() << "," << ants[i]->getY() << "]" << endl;
    }
}
