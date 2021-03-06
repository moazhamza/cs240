#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class Node{
public:
    T *data;
    Node *next;
/* Node constructor which takes data of type T */
    Node(T *data){
        this->data = data;
        next = nullptr;
    }
    ~Node(){
        delete data;
    }
};

template <class T>
class LinkedList{
private:
    Node<T> *head;
    Node<T> *curr;
    template<class U> friend class Queue;
/* Finds the last node in order to add to it */
    Node<T>* findLastNode(){
        Node<T> *currentNode = head;
        while(currentNode->next != nullptr) currentNode = currentNode->next;
        return currentNode;
    }

public:
    // Constructor
    LinkedList(){
        head = nullptr;
    }
    // Copy constructor
    LinkedList(const LinkedList<T>& sll){
        Node<T> *newHead = new Node<T>(sll.head->data);
        this->head = newHead;
        Node<T> *currNode = sll.head;
        while(currNode != nullptr){
            this->insert(currNode->data);
            currNode = currNode->next;
        }
    }
    // Destructor -- Deletes all nodes in list 
    ~LinkedList(){
        Node<T> *next, *curr;
        for(curr = head; curr != nullptr; (curr = next)){
            next = curr->next;
            delete curr;
        }
    }
    // Inserts a copy of data (allocated on the heap) into the list
    bool insert(T data){
        T *dataPtr = new T(data);
        Node<T> *newNode = new Node<T>(dataPtr);
        if(empty()){
            head = newNode;
            curr = head;
            return true;
        }
        Node<T> *lastNode = findLastNode();
        lastNode->next = newNode;
        return true;
    }
    // Returns a reference to the next item in the list. Curr is advanced 
    T& read(){
        T * returnData = (curr->data);
        curr = curr->next;
        return *returnData;
    }
    // Checks if list is empty
    bool empty(){
        return head == nullptr;
    }
    // Removes the first instance of data in the list 
    bool remove(T &data){
        Node<T> *prev = nullptr;
        for(Node<T> *currToDelete = head; currToDelete != nullptr; currToDelete = currToDelete->next){
            if(*(currToDelete->data) == data) {
                if(prev != nullptr) prev->next = currToDelete->next;
                else head = currToDelete->next;
                delete currToDelete;
                curr = head;
                return true;
            }
            prev = curr;
        }
        return false;
    }

};
#endif
