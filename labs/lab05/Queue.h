#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class T>
class Queue{
private:
    LinkedList<T> list;
public:
    bool enqueue(T data){
        T *dataHeap = new T(data);
        return list.insert(*dataHeap);
    }
    T& dequeue(){
        T *returnData = &list.read();
        list.remove(*returnData);
        return *returnData;
    }
    T peek(){
        return list.head->data;
    }
    bool empty(){
        return list.head == nullptr;
    }
    void clear(){
        while(list.head != nullptr) list.remove(*(list.head->data));
    }
};

#endif
