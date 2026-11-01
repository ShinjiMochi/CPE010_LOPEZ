#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree{
    private:
        // Key creation
        T key;
        // Pointers for left and right
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;
    public:
        // Constructor Function
        BinarySearchTree(T val);

        // Insert Left and Right
        void insert(T val);

        // Traversing Tree
        void preOrder();
        void inOrder();
        void postOrder();

        // Searching
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T val){
    key = val;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T val){
    // Left or Right

    // Go left 
   if(val < key){
        if(left == nullptr){
            left = new BinarySearchTree<T>(val);
        }
        else{
            left->insert(val);
        }
    }
    else if(val > key){
        if(right == nullptr){
            right = new BinarySearchTree<T>(val);
        }
        else{
            right->insert(val);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder(){

    std::cout << "The current node is: " << key <<"\n";
    if(left != nullptr){
        left->preOrder();
    }   
    
    if(right != nullptr){
        right->preOrder();
    }

}

template <typename T>
void BinarySearchTree<T>::inOrder(){

    if(left != nullptr){
        left->inOrder();    
    }   
    std::cout << "The current node is: " << key <<"\n";
    if(right != nullptr){
        right->inOrder();
    }

}

template <typename T>
void BinarySearchTree<T>::postOrder(){

    if(left != nullptr){
        left->postOrder();    
    }   
    if(right != nullptr){
        right->postOrder();
    }
    std::cout << "The current node is: " << key <<"\n";

}

#endif 