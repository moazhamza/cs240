#include "Card.h"

#define LOW_SUIT 1
#define HIGH_SUIT 4
#define LOW_VAL 2
#define HIGH_VAL 14

/* Constructor for card. Must be a valid playing card suit and value. */
Card::Card(int suit, int value){
    if(suit >= LOW_SUIT && suit <= HIGH_SUIT) this->suit = suit;
    if(value >= LOW_VAL && value <= HIGH_VAL) this->value = value;
}

/* Cards are equal if they have the same value and suit */
bool Card::operator==(const Card &other){
    return (suit == other.suit && value == other.value);
}
