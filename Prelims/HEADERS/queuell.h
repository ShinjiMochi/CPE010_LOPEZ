#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode {
    public:
    T data; 
    qNode* next;
};

template <typename T>
qNode<T>* new_node(T newData){
    // Create a newNode for newData
    qNode<T>* newNode = new qNode<T>();
    newNode -> data = newData;

    // Let newNode point to current top and overwrite
    newNode -> next = nullptr;

    return newNode;
}

// isEmpty
template <typename T>
bool isEmpty(qNode<T>** frontPtr, qNode<T>** backPtr) {
   return ((*frontPtr) == nullptr && (*backPtr) == nullptr);
}

// enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {
    qNode<T>* newNode = new_node(newData);

    if(isEmpty(frontPtr, backPtr)){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    (*backPtr) -> next = newNode;
    (*backPtr) = newNode;
}

// dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
   
   if(isEmpty(frontPtr, backPtr)){
    std::cout << "The queue is empty" << std::endl;
    return;
   }

   qNode<T>* deleteTemp = nullptr;

    deleteTemp = (*frontPtr);

    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr) -> next;
    deleteTemp->next = nullptr;

    delete deleteTemp;
}

// Display Stack
template <typename T>
void displayAll(qNode<T>** frontPtr, qNode<T>** backPtr) {

    if (isEmpty(frontPtr, backPtr)) {
        std::cout << "The queue is empty" << std::endl;
        return;
    }

    qNode<T>* current = (*frontPtr);

    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

#endif