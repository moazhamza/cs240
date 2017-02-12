#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"

class AntHill{

    private:
        int current_ants;
        List *listOfAnts = new List();
        int next_id;

    public:
        AntHill();
        ~AntHill();

        int addAnt();
        bool removeAnt(int);

        Ant *getAnt(int);
        int getCurrentNumAnts(){return current_ants;}

        void move();

        void printHillInfo();

};

#endif 
