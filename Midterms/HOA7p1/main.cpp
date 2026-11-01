#include <iostream>
#include <cstdlib>
#include <ctime>   
#include "sortingAlgos.h"

const int max_Size = 100;

int main(){
    int testArray[max_Size]; 

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < max_Size; i++) {
        testArray[i] = (std::rand() % 100) + 1;
    }

    std::cout << "Unsorted Array" << std::endl;
    for (int i = 0; i < max_Size; i++ ) {
        std::cout << testArray[i] << ' ';

        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
    
    bubbleSort(testArray, max_Size);
    //insertionSort(testArray, max_Size);
    //selectionSort(testArray, max_Size);

    std::cout << std::endl << std::endl;

    std::cout << "Insertion Sorted Array" << std::endl;
    for (int i = 0; i < max_Size; i++ ) {
        std::cout << testArray[i] << ' ';

        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
}