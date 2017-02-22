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
    Ant(const Ant&);
    
    void move();
    void move(int);
    bool fight(Ant *);
    
    int getID(){return this->id;}
    int getX(){return this->x;}
    int getY(){return this->y;}
    int getEXP(){return this->exp;}
    void setEXP(int exp){this->exp = exp;}
};


#endif
