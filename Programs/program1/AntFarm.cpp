#include "AntFarm.h"

AntFarm::AntFarm(){
    this->antHill = new AntHill();
    // AntHills start with 3 Ants;
    for(int i=0; i<3;i++) antHill->addAnt();
}

