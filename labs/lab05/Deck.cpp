#include "Deck.h"

#include <cstdlib>

#define LOW_VAL 2
#define HIGH_VAL 14
#define LOW_SUIT 1
#define HIGH_SUIT 4

#define CARDS_IN_DECK 52
#define INALID_CARD_NUM -1
#define NUM_CARDS_PER_SUIT 13


/* Deck constructor - Creates deck with all proper playing cards */
Deck::Deck(){
    for(int val=LOW_VAL; val<=HIGH_VAL; val++){
       for(int suit=LOW_SUIT; suit<=HIGH_SUIT; suit++)
            this->deck.enqueue(Card(suit,val));
    }
}
/* Deck destructor - Removes all cards from deck */
Deck::~Deck(){
    while(!deck.empty()){
        deck.dequeue();
    }
}
/* Local method which checks if num is in arr */ 
bool isAlreadyUsed(int num, int arr[]){
    for(int i=0; i < CARDS_IN_DECK; i++){
        if(num == arr[i]) return true;
    }
    return false;
}

/* Shuffles the deck */
void Deck::shuffle(){
    int arr[CARDS_IN_DECK];
    // Fill array with default invalid value
    for(int i=0;i<CARDS_IN_DECK;i++) arr[i] = {INALID_CARD_NUM};
    // Loop through array and create a random number
    for(int i=0; i < CARDS_IN_DECK; i++){
        int rNum = rand() % CARDS_IN_DECK;
        // If the number is already been used then keep generating random numbers until
        // you find one that hasn't been used yet.
        while(isAlreadyUsed(rNum, arr)){
            rNum = rand() % CARDS_IN_DECK;
        }
        // Assign the random number to the array
        arr[i] = rNum;
    }
    // Each number corressponds to a card. This will be the new order of the cards.
    this->deck.clear();
    for(int i=0; i<CARDS_IN_DECK; i++){
        deck.enqueue(Card((arr[i] / NUM_CARDS_PER_SUIT) + 1, arr[i] % NUM_CARDS_PER_SUIT + 2));
    }
    
    
}
