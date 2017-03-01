#ifndef Card_h
#define Card_h

class Card {
private:
    int suit;
    int value;
public:
    Card(int,int);
    int getSuit();
    int getValue();

    
    bool operator==(const Card &other);
};





#endif
