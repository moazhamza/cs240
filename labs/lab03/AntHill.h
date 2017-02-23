#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"

class AntHill{

    private:
        int current_ants;
        Ant **ants;
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
