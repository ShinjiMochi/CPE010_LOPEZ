#ifndef ILOC_H
#define ILOC_H

#include <iostream>
#include <string>

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
    qNode(const T& newData)
        : data(newData), next(nullptr) 
    {
    }
};

// ------- Queue Operations ------- //

template <typename T>
qNode<T>* new_node(const T& newData) {

    qNode<T>* newNode = new qNode<T>(newData);

    return newNode;
}

template <typename T>
bool isEmpty(qNode<T>** frontPtr, qNode<T>** backPtr) {

    return ((*frontPtr) == nullptr && (*backPtr) == nullptr);
}

template <typename T>
void enqueue(const T& newData, qNode<T>** frontPtr, qNode<T>** backPtr) {

    qNode<T>* newNode = new_node(newData);

    if (isEmpty(frontPtr, backPtr)) {

        (*frontPtr) = newNode;
        (*backPtr) = newNode;

        return;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {

    if (isEmpty(frontPtr, backPtr)) {

        std::cout << "The queue is empty" << std::endl;
        return;
    }

    qNode<T>* deleteTemp = (*frontPtr);

    if ((*frontPtr) == (*backPtr)) {

        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;

        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;

    deleteTemp->next = nullptr;

    delete deleteTemp;
}

#endif

