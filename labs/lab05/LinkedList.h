#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class Node{
public:
    Node(T* data){
        this->data = data;
        next = nullptr;
   }
    T* data;
    Node *next;
};

template <class T>
class LinkedList{
private:
    Node<T> *head;
    Node<T> *curr;
public:
    LinkedList(){
        head = nullptr;   
    }
    LinkedList(const LinkedList<T>& sll){
        this->head = sll.head; 
    }
    ~LinkedList(){
        Node<T> *next, *curr;
        for(*curr = head; curr != nullptr; (curr = next)){ 
            next = curr->next;
            delete curr;
        }        
    }
    
    void insert(T data){
        Node<T> curr;
        for(curr = head; curr->next != nullptr; curr = curr->next);
        Node<T> newNode(data);
        curr->next = newNode;
    }

    T& read(){
        T ret = curr->data;
        curr = curr->next;
        return ret;
    }

    bool empty(){
        return head == nullptr;
    }

    bool remove(T &data){
        Node<T> *prev = nullptr;
        for(curr = head; curr != nullptr; curr = curr->next){
            if(curr->data == data) {
                if(prev != nullptr) prev->next = curr->next;
                delete curr;
                return true;                
            }
            prev = curr;
        }
        return false;
    }
    
};
#endif
