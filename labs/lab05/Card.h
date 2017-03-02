#ifndef Card_h
#define Card_h

class Card {
private:
    int suit;
    int value;
public:
    Card(int,int);
    int getSuit(){return suit;}
    int getValue(){return value;}

    
    bool operator==(const Card &other);
};
#endif
