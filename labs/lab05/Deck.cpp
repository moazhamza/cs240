#include "Deck.h"

#include <cstdlib>

Deck::Deck(){
    for(int val=2; val<=14; val++){
        for(int suit=1; suit<=4; suit++)
            this->deck.enqueue(Card(suit,val));
    }
}

Deck::~Deck(){
    while(!deck.empty()){
        deck.dequeue();
    }
}

bool isAlreadyUsed(int num, int arr[]){
    for(int i=0; i < 52; i++){
        if(num == arr[i]) return true;
    }
    return false;
}


void Deck::shuffle(){
    int arr[52];
    // Fill array with default invalid value
    for(int i=0;i<52;i++) arr[i] = {-1};
    // Loop through array and create a random number
    for(int i=0; i < 52; i++){
        int rNum = rand() % 52;
        // If the number is already been used then keep generating random numbers until
        // you find one that hasn't been used yet.
        while(isAlreadyUsed(rNum, arr)){
            rNum = rand() % 52;
        }
        // Assign the random number to the array
        arr[i] = rNum;
    }
    // Each number corressponds to a card. This will be the new order of the cards.
    this->deck.clear();
    for(int i=0; i<52; i++){
        deck.enqueue(Card((arr[i] / 13) + 1, arr[i] % 13 + 2));
    }
    
    
}
