#include "AntHill.h"
#include "LinkedList.h"

class AntFarm{
    private:
        AntHill *antHill;
        int food; 
    public:
        AntFarm();
        int getNumFood(){return food;}
        
};
