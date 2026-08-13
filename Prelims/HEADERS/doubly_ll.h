#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

// Creating a node
template <typename T>
DoubleList<T> *createnewNode(T newData){
    // Dynamically allocate memory for the node
    DoubleList <T> *newNode = new DoubleList<T>;
    // Store the data in the node
    newNode->data = newData;

    // Point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the address of the newly created node
    return newNode;
}

template <typename T>
void dllTravers(DoubleList<T>* currentNode){

    DoubleList<T> *tail;

    // check if the list is empty
    if(currentNode == nullptr){
        std::cout << "The list is empty" << std::endl;
        return;
    }
    // move forward
    std::cout << "Going Forwards:" << std::endl;
    while(currentNode != nullptr){
        std::cout<< currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    // add a new line
    std::cout<<std::endl;

    // move backward
    std::cout << "Going Backwards:" << std::endl;

    while(tail != nullptr){
        std::cout<< tail->data << " ";
        tail = tail->prev;
    }
};

// Insertion at the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    // creating a new node
    DoubleList<T>* newNode = createnewNode(newData);
    
    //new node should point to the current head
    newNode->next = *currentHead;

    //current head should point back to the newNode
    (*currentHead)->prev = newNode;

    //update the pointer head
    *currentHead = newNode;
}

template<typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    //Create a new Node
    DoubleList<T>* newNode = createnewNode(newData);

    //Traverse until the end of the node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    // connect the end node to the new node
    currentHead->next = newNode;
    // connect the new node back to the last one
    newNode->prev = currentHead;
}

// General Insert
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Previous value cannot be null"<<std::endl;
        return;
    }
    DoubleList<T>* nextNode;
    DoubleList<T>* newNode  = createnewNode(newData);

    // Creating and storing
    newNode->data = newData;
    nextNode = prevNode->next;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    nextNode->prev = newNode;


}

//Deleting a Node

#endif