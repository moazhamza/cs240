#include "LinkedList.h"

#include <iostream>

using namespace std;

int main(){

    cerr << "------------ Creating an empty list ---------------" << endl;

    List l = *(new List());

    l.printList();



}
