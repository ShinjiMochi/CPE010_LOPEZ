#include "node.h"
#include <iostream>

#ifndef SEARCHALG_H
#define SEARCHALG_H



// -------------------- ARRAY --------------------

template<typename T>
void linearSearch(int size,T item,T array[]){
    int count = 0;
    for (int i = 0; i < size; i++){
        if(array[i] == item){
            std::cout << "Data Found at index " << i << "\n";
            std::cout << "Elements found: " << ++count << "\n";
        }
    }
    if (count > 0) {
        return;
    }
    std::cout << "Data not found\n";
}

template<typename T>
void binarySearchArr(T data[],int arrSize,T dataFind){
    int low = 0;
    int high = arrSize - 1;
    int middle;
    int iteration = 1;

    while (low <= high){
        middle = (int)((low+high)/2);

        std::cout << "[Iteration " << iteration++ << "] "
                  << "low: " << low << ", high: " << high 
                  << ", middle: " << middle << " (value: " << data[middle] << ")\n";

        if (dataFind == data[middle]){
            std::cout << "The data was found\n";
            return;
        }
        else if (dataFind < data[middle]){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }

    std::cout << "The data was not found\n";
}

template<typename T>
void binarySearchRecurs(T data[], int low, int high, T dataFind) {
    if (low > high) {
        std::cout << "The data was not found\n";
        return;
    }
    int middle = low + (high - low) / 2;

    std::cout << "Checking low: " << low << ", high: " << high 
              << ", middle: " << middle << " (value: " << data[middle] << ")\n";

    if (data[middle] == dataFind) {
        std::cout << "The data was found\n";
        return;
    }

    if (dataFind < data[middle]) {
        binarySearchRecurs(data, low, middle - 1, dataFind);
    } else {
        binarySearchRecurs(data, middle + 1, high, dataFind);
    }
}

//--------------------------------------------------------------------------------

//-------------------- LINKED LIST --------------------
template<typename T>
void linearSearchLL(Node<T> *headNode, T dataToBeFound){
    int count = 0;
    while (headNode != nullptr){
        if (headNode -> data == dataToBeFound){
            std::cout << "Found Data inside node\n";
            std::cout << "Elements found: " << ++count << "\n";
        }
        headNode = headNode -> next;
    }
    if (count > 0) {
        return;
    }
    std::cout << "Data not found in given nodes\n";
}

template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != end && fast -> next!= end){
        slow = slow -> next;

        fast = fast -> next -> next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    Node<T>* last = nullptr;
    
    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if (middle -> data == dataFind) {
            std::cout << "Data found\n";
            return;
        }
        else if (middle -> data > dataFind) {
            last = middle;
        }
        else {
            start = middle -> next; 
        }
    }

    std::cout << "Data not found\n";
}

#endif