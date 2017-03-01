#ifndef DECK_H
#define DECK_H

#include "Queue.h"
#include "Card.h"

class Deck {
private:
    Queue<Card> deck;
    
public:
    Deck();
    ~Deck();
    
    Card draw(){return deck.dequeue();}
    bool empty(){return deck.empty();}
    void shuffle();
};

#endif
