#include <iostream>
#include "BST.h"

int main(){

    // Root node creation
    BinarySearchTree<int> tree(2);

    // Value insertion
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "\nPre Order: " << std::endl;
    tree.preOrder();

    std::cout << "\nIn Order: " << std::endl;
    tree.inOrder();

    std::cout << "\nPost Order: " << std::endl;
    tree.postOrder();

    return 0;
}