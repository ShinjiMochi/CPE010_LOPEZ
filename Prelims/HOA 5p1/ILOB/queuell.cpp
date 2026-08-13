#include <iostream>
#include "queuell.h"

int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    if (isEmpty(&front, &back)) {
    std::cout << "Queue is empty\n";
    } else {
    std::cout << "Queue is not empty\n";
    }

    enqueue('S', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('H', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('I', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    enqueue('N', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;

    displayAll(&front, &back);

    if (isEmpty(&front, &back)) {
    std::cout << "Queue is empty\n";
    } else {
    std::cout << "Queue is not empty\n";
    }

    std::cout << "\nTesting dequeue operator \n";
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    dequeue(&front, &back);

    if (isEmpty(&front, &back)) {
    std::cout << "Queue is empty\n";
    } else {
    std::cout << "Queue is not empty\n";
    }

}

