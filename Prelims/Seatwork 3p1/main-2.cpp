#include <iostream>
#include "singly_ll.h"

int main() {

    // CREATING A NODE STORED IN THE STACK
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;
    SingleList<char>* fifth = nullptr;

    // ALLOCATES MEMORY
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    fifth = new SingleList<char>;

    head->data = 'S';
    second->data = 'H';
    third->data = 'I';
    fourth->data = 'N';
    fifth->data = 'G';

    // LINKING THE NODES:
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    std::cout << "Testing of traversal\n";
    ListTraversal(head);

    std::cout << "Testing of sllinsertHead\n";
    sllinsertHead('Q', &head); 
    ListTraversal(head);

    std::cout << "Testing of sllGeneralInsert\n";
    sllGeneralInsert('X', head->next->next); 
    ListTraversal(head);

    std::cout << "Testing of sllinsertEnd\n";
    sllinsertEnd('U', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting the node\n";
    sllDeleteNode('U', &head);
    ListTraversal(head);

    std::cout << "Deleting all nodes\n";
    sllDeleteList(&head);
    ListTraversal(head);    

    return 0;
}

