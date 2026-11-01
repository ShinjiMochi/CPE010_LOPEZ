#include <iostream>
#include "queueArr.h"

int main()
{
    // creating an object
    queueArr<char> q(5);

    // enqueue 'S' 'H' 'I' 'N':
    q.enqueue('S');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('N');

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    // Enqueue 'G'

    q.enqueue('G');
    std::cout << "\nFront: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    std::cout << std::endl;
    
    // testing the clear
    q.Clear();

    std::cout << "is the queue empty? "
              << (q.Empty() ? "yes" : "no")
              << std::endl;

    return 0;
}
