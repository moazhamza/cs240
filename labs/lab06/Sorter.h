#ifndef SORTER_h
#define SORTER_h

#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <iostream>

template <class T>
class Sorter {
private:
    T container;
    bool isAlreadyUsed(int num, int arr[], unsigned long size){
        for(unsigned long i=0; i < size; i++){
            if(num == arr[i]) return true;
        }
        return false;
    }
    typename T::iterator at(int i){
        typename T::iterator current = container.begin();
        for(int j=0; j < i; j++) current++;
        return current;
    }
    
public:
    // default constructor
    Sorter(){
        container = T();
    }
    // Clears all the data in the container
    void clear(){
        container.clear();
    }
    // Returns number of elements in the container
    unsigned int size(){
        return (unsigned int)container.size();
    }
    // Inserts value into container (Appended)
    void insert(int i){
        container.push_back(i);
    }
    // Shuffles values in container to a random order
    void shuffle(){
        int arr[container.size()];
        // Fill array with default invalid value
        for(unsigned int i=0;i<container.size();i++) arr[i] = -1;
        // Loop through array and create a random number
        for(unsigned int i=0; i < container.size(); i++){
            unsigned int rNum = rand() % container.size();
            // If the number is already been used then keep generating random numbers until
            // you find one that hasn't been used yet.
            while(isAlreadyUsed(rNum, arr, container.size())){
                rNum = rand() % container.size();
            }
            // Assign the random number to the array
            arr[i] = rNum;
        }
        // Each element in the array corressponds to the index of the element in the old container. List them as such
        
        T newContainer = T();
        
        for(unsigned int i=0; i < container.size(); i++){
            typename T::iterator iter = container.begin();
            for(int j=0; j < arr[i]; j++) iter++;
            newContainer.push_back(*iter);
        }
        
        container = newContainer;
        
        
        
    }
    // Overloaded indexing operator, returns iterator at index i
    typename T::iterator operator[](int i){
        typename T::iterator current = container.begin();
        for(int j=0; j < i; j++) current++;
        return current;
    }
    // Sorts container using insertion sort algorithm
    void insertionSort(){
        auto begin = std::chrono::high_resolution_clock::now();
        
        for(unsigned int i=0; i<container.size(); i++){
            for(unsigned int j=i; j > 0 && *(this->at(j)) < *(this->at(j-1)); j--) iter_swap((*this)[j], (*this)[j-1]);
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        
        std::cout << "Insertion sort time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanoseconds" << std::endl;
        
    }
    
    // Sorts container using selection sort algorithm
    void selectionSort(){
        auto begin = std::chrono::high_resolution_clock::now();
        
        for(unsigned int i=0; i < container.size(); i++){
            int min = i;
            for(unsigned int j=i+1; j < container.size(); j++){
                if(*(this->at(j)) < *(this->at(min))) min = j;
            }
            iter_swap(this->at(i), this->at(min));
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        
        std::cout << "Selection sort time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanoseconds" << std::endl;
        
    }
    
    // Sorts container using bubble sort algorithm
    void bubbleSort(){
        auto begin = std::chrono::high_resolution_clock::now();
        bool swapped = true;
        while(swapped){
            swapped = false;
            for(unsigned int i=0;i<container.size();i++){
                if((i+1 < container.size()) && *(this->at(i)) > *(this->at(i+1))){
                    std::iter_swap(this->at(i), this->at(i+1));
                    swapped = true;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        
        std::cout << "Bubble sort time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanoseconds" << std::endl;
        
        
        
    }
    
    
};

#endif /* Sorter_h */
