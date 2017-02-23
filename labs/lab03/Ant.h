#ifndef ANT_H
#define ANT_H

class Ant{
    private:
        int id;
        int x;
        int y;
        int exp;
    public:
        Ant(int);
        Ant();
        void move();
        Ant *fight(Ant *);

        int getID(){return this->id;}
        int getX(){return this->x;}
        int getY(){return this->y;}
        int getEXP(){return this->exp;}
        void setEXP(int exp){this->exp = exp;}
};





#endif
