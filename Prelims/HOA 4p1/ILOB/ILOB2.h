#ifndef ILOB2_H
#define ILOB2_H

#include <iostream>

template <typename T>
class Node {
    public:
    T data; 
    Node* next;
};

template <typename T>
Node<T>* head = nullptr;

// Push
template <typename T>
void push(T newData) {
    // Create a newNode for newData
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;

    // Let newNode point to current top and overwrite
    newNode->next = head<T>;
    head<T> = newNode;
}

// Pop
template <typename T>
T pop() {
    // Check if stack is empty
    if (head<T> == nullptr) {
        std::cerr << "Stack Underflow: Cannot pop from an empty stack." << std::endl;
        return T();
    }

    // Save top node
    Node<T>* temp = head<T>;
    // Store value
    T tempVal = temp->data;

    // Move the top to the next
    head<T> = head<T>->next;

    // Remove the node
    delete temp;

    // Return the removed value
    return tempVal;
}

// isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// Top
template <typename T>
void Top() {
    // Checking if stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack is empty. No top element." << std::endl;
        return;
    }
    // Print Top
    std::cout << "Top element: " << head<T>->data << std::endl;
}

// Display Stack
template <typename T>
void displayALL() {
    // Check if the stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow\n" << std::endl;
        return;
    }

    // Traverse the stack then print 
    Node<T>* temp = head<T>;
    std::cout << "Stack elements: \n";
    while (temp != nullptr) {
        std::cout << temp->data << " \n";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif
