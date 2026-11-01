#ifndef NODES_H
#define NODES_H

template<typename T>
class Node{
public: 
    T data;
    Node *next = nullptr;
    Node *prev = nullptr;

};

template<typename T>
Node<T> *new_node(T newData){
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;

}

#endif