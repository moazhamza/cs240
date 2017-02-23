#include "DogShelter.h"
#include <fstream>

using namespace std;

DogShelter::DogShelter(int max_dogs){
    this->max_dogs = max_dogs;    
}

bool DogShelter::addDog(Dog d){
    if(next_id < max_dogs){
        this->dogs[next_id] = d; 
        next_id++;
        return true; 
    } 
    else return false;
}
bool DogShelter::adopt(int id){
    bool found = false;
    int dogIndex = 0;
    for(int i=0; i < this->current_num; i++){
        if (dogs[i].id == id) {
            found = true;
            dogIndex = i;
            break;
        }
    }
    if(found){
        ofstream adoptedFile("adopted.txt");
        if (adoptedFile.is_open()){
            adoptedFile << "ID: " << dogs[dogIndex].id << ", Breed: " << dogs[dogIndex].breed << endl;
        adoptedFile.close();
        }
       

        for(int j=0; j< current_num; j++){

        }
    }
}
