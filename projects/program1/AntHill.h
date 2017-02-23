#ifndef ANTHILL_H
#define ANTHILL_H

#include <fstream>

#include "Ant.h"
#include "LinkedList.h"

class AntHill{
    
private:
    int current_ants;
    List *listOfAnts = new List();
    int next_id;
    unsigned int food;
    int grid_size;
    unsigned int num_attacks;
    unsigned int losses;
    std::fstream logfile;
    
public:
    AntHill();
    ~AntHill();
    
    int addAnt();
    bool removeAnt(int);
    
    Ant *getAnt(int);
    int getCurrentNumAnts(){return current_ants;}
    unsigned int getFood(){return food;}
    
    int determineNumDefenders();
    void removeDefendingAnts();
    
    void attack(std::fstream&);
    void move();
    void fightOrFood(std::fstream&);
    
    void outputHillStatus(std::fstream&);
    void printHillInfo();
    void turn();
};

#endif
