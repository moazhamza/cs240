#include "LinkedList.h"
#include "Ant.h"

#include <iostream>

using namespace std;

int main(){

    cerr << "------------ Creating an empty list ---------------" << endl;

    List l = *(new List());

    l.printList();

    cerr << "------------ Adding Ants to the list -------------" << endl;

    cerr << "------------ Adding 1 ant to the list -------------" << endl;


    Ant *newAnt = new Ant(0);

    l.addAnt(newAnt);

    l.printList();

    cerr << "------------ Adding 100 ant to the list -------------" << endl;

    for(int i=1; i < 100; i++){
        Ant *nextAnt = new Ant(i);
        l.addAnt(nextAnt);
    }  

    l.printList();

    cerr << "----------- Copying the list to a new list -------------" << endl;

    List nl = *new List(l);

    nl.printList();


    cerr << "----------- Deleting the odd members of the list --------" << endl;

    int i=0;
    Ant *nextAnt = l.findAnt(i);

    while(nextAnt != 0){
        if(nextAnt->getID() % 2 == 1) l.deleteAnt(nextAnt->getID());
        i++;
        nextAnt = l.findAnt(i);
    } 

    l.printList();

    cerr << "--------- Deleting Ant with ID 64 ------------------" << endl;

    l.deleteAnt(64);
    l.printList();

    cerr << "--------- Adding ant with ID 1001 using << operator --" << endl;

    Ant *operatorAnt = new Ant(1001);

    l <<  operatorAnt;

    l.printList();
}   
