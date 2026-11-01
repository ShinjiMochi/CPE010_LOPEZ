#ifndef SEARCH_CORE_H
#define SEARCH_CORE_H
#include "nodes.h"

template<typename T>
int linearSearchAR(int size, T dataFind, T array[]){
    
    int comparisons = 0;
    int matches = 0;

    for(int j = 0; j < size; j++){ 
        comparisons++;
        if(dataFind == array[j]){
            matches++;
        }

    }
    if(matches > 0){
        std::cout<<"Searching is successful\n";
    } else {
        std::cout<<"Searching is unsuccessful\n";
    }
    std::cout<<"Found comparisons: "<<comparisons<<"\n";
    std::cout<<"Found matches: "<<matches<<"\n";
    return matches; 

}

template<typename T>
int linearSearchLL(Node<T> *head, T dataFind){
    // Traverse the entire list and count every matching node.
    int comparisons = 0;
    int matches = 0;

    while(head != nullptr){
        comparisons++;
        if(head->data == dataFind){
            matches++;
        }
        // move on to the next node
        head = head->next;
    }
    if(matches > 0){
        std::cout<<"The data: "<< dataFind<< " was Found successfully.\n";
    } else {
        std::cout<<"Searching is unsuccessful.\n";
    }
    std::cout<<"Found comparisons: "<<comparisons<<"\n";
    std::cout<<"Found matches: "<<matches<<"\n";
    return matches;
}

template<typename T>
int binarySearchArr(const T data[], int arrSize, T dataFind){
    int low = 0;
    int high = arrSize - 1;
    int iterations = 0;

    while (low <= high){
        int middle = low + (high - low) / 2;
        iterations++;

        std::cout<< "Iteration: "<<iterations<<"\n";
        std::cout<< "Low: "<<low<<"\n";
        std::cout<< "High: "<<high<<"\n";

        if (data[middle] == dataFind){
            std::cout<<"The data was found\n";
            return iterations;
        }
        else if (data[middle] < dataFind){
            low = middle + 1;
        }
        else{
            high = middle - 1;
        }
    }

    std::cout<<"The data was not found\n";
    return iterations;
}

template<typename T>
int binarySearchRecursive(const T data[], int low, int high, T dataFind, int &iterations){
    if (low > high){
        std::cout<<"The data was not found\n";
        return iterations;
    }

    int middle = low + (high - low) / 2;
    iterations++;

    std::cout<< "Iteration: "<<iterations<<"\n";
    std::cout<< "Low: "<<low<<"\n";
    std::cout<< "High: "<<high<<"\n";

    if (data[middle] == dataFind){
        std::cout<<"The data was found\n";
        return iterations;
    }
    else if (data[middle] < dataFind){
        return binarySearchRecursive(data, middle + 1, high, dataFind, iterations);
    }
    else{
        return binarySearchRecursive(data, low, middle - 1, dataFind, iterations);
    }
}

#endif //SEARCH_CORE_H