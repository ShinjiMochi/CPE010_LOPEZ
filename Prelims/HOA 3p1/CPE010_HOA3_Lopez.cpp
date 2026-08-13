#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){

    // Create a List 'C P E'
    DoubleList<char> * head = createnewNode('S');
    DoubleList<char> * second = createnewNode('H');
    DoubleList<char> * third = createnewNode('I');
    DoubleList<char> * fourth = createnewNode('N');

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    //traversal
    std::cout<<"Testing the DLL Traversal" << std::endl;
    dllTravers(head);

    // Testing insert node at head
    std::cout<<"\n\nTesting the DLL Insertion (Head)" << std::endl;
    dllInsertHead('X', &head);
    dllTravers(head);

    // Testing insert node at end
    std::cout<<"\n\nTesting the DLL Insertion (Tail)" << std::endl;
    dllInsertEnd('G', head);
    dllTravers(head);

    std::cout<<"\n\nTesting the DLL Insertion (General)" << std::endl;
    dllGeneralInsert('H', head);
    dllTravers(head);

}