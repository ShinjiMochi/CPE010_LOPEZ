#include <iostream>
#include <cstdlib> // random integers
#include <time.h> // seeding function

#include "node.h"
#include "searchAlg.h"

const int max_size = 10;

int main(){

    int dataList[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    Node<int>* headNode = newNode(dataList[0]);
    Node<int>* tail = headNode;

    for (int i = 1; i < max_size; i++){
        tail -> next = newNode(dataList[i]);
        tail = tail -> next;
    };

    binarySearchRecurs(dataList, 0, max_size - 1, 8);

    return 0;
}
