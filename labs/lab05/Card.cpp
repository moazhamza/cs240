#include "Card.h"

Card::Card(int suit, int value){
    if(suit >= 1 && suit <= 4) this->suit = suit;
    if(value >= 2 && value <= 14) this->value = value;
}

int Card::getSuit(){
    return suit;
}
int Card::getValue(){
    return value;
}

bool Card::operator==(const Card &other){
    return (suit == other.suit && value == other.value);
}
