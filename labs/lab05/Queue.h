#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class T>
class Queue{
private:
    LinkedList<T> list;
public:
    /* Adds a copy of data to the queue by adding it to the Linked List */
    bool enqueue(T data){
        T *dataHeap = new T(data);
        list.insert(*dataHeap);
        delete dataHeap;
        return true;
    }

    /* Returns whatever is at the top of the linked list and removes it which
     * gives the first in item */
    T dequeue(){
        T returnData = list.read();
        list.remove(returnData);
        return returnData;
    }
    /* Views the first item in the queue */
    T peek(){
        return list.head->data;
    }
    /* Checks if the queue is empty */
    bool empty(){
        return list.head == nullptr;
    }
    /* Clears all items in queue */
    void clear(){
        while(list.head != nullptr) list.remove(*(list.head->data));
    }
};

#endif
