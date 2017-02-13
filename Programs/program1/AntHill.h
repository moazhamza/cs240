#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"

class AntHill{

    private:
        int current_ants;
        List *listOfAnts = new List();
        int next_id;
        unsigned int food;
        int gridSize;
    public:
        AntHill();
        ~AntHill();

        int addAnt();
        bool removeAnt(int);

        Ant *getAnt(int);
        int getCurrentNumAnts(){return current_ants;}
        unsigned int getFood(){return food;}

        void attack(); 
        void move();
        

        void printHillInfo();
        void turn();
};

#endif 
