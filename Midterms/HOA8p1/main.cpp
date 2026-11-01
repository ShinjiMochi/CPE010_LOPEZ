#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgos2.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main(){

    // create arrays with unsorted values
    int unsortedArr[maxSize];
    int unsortedArr2[maxSize];
    int unsortedArr3[maxSize];
    // use time (0) as seed for random
    srand(time(0));
    // insert random values within maximum range
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
        unsortedArr2[i] = rand()%100;
        unsortedArr3[i] = rand()%100;
    }
    
    // std::cout << "Unsorted Array:\n";
    // displayArr(unsortedArr);
    
    // std::cout << "\nArray sorted using shell sort\n";
    // shellSort(unsortedArr, maxSize, 0);
    // displayArr(unsortedArr);

    // std::cout << "\nArray sorted using quick sort\n";
    // quickSort(unsortedArr2,0,maxSize-1);
    // displayArr(unsortedArr2);

    // std::cout << "\nArray sorted using merge sort\n";
    // mergeSort(unsortedArr3, 0, maxSize-1);
    // displayArr(unsortedArr3);

        
    std::cout << "\nSorted array with partition shell and merge\n";
    partiMerge(unsortedArr, 0, maxSize-1);
    partiShell(unsortedArr2, maxSize);

    std::cout << "\nSorted Array 1:\n";
    displayArr(unsortedArr);

    std::cout << "\nSorted Array 2:\n";
    displayArr(unsortedArr2);

    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if ((i%10) == 9){
            std::cout << '\n';
        }
    }
}