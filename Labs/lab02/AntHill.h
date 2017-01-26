#ifndef ANTHILL_H
#define ANTHILL_H

#define TOTAL_MAX_ANTS 100

class Ant{
    private:
       int id;
       int x;
       int y;

    public:
       Ant();
       Ant(int ID);

       void move();

       int getID();
       int getX();
       int getY();
};  

class AntHill{
    private:
        int max_ants;
        int current_ants;
        Ant ants[TOTAL_MAX_ANTS];
        int next_id;
    public:
        AntHill(int);
        bool addAnt();
        Ant getAnt(int);
        void move();
        bool changeMax(int);
        void printHillInfo();
        int getCurrentNumAnts();
        int getMaxAnts();
};

#endif 
