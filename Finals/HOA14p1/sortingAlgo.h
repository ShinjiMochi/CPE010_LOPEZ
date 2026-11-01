#include <cstddef>
#include <iostream>
#ifndef SORTING_H
#define SORTING_H


template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    //step 1: for i = 0 to N-1 repeat inner loop
    for (int i = 0; i < arrSize; i++) {
        //step 2: inner loop that for K = i+1 to N-1 repeat
        for (int j = i + 1; j < arrSize; j++) {
            //step 3: swap if the arr[j] is greater than arr[i]
            if (arr[i] > arr[j]) {
                //swap arr[j] and arr[i]
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
//array, current position, size of array
int routineSmallest(T arr[], int K, const int arrSize) {
    int position, j;
    T smallestElement = arr[K];
    
    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElement) {
            smallestElement = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass;
    for (int i = 0; i < arrSize; i++) {
        POS = routineSmallest(arr, i, arrSize);
        //swapping 
        temp = arr[i];
        arr[i] = arr[POS];
        arr [POS] = temp;
        
        //for verification and counting the number of passes that was done
        pass++;
        }
    }

template <typename T>
void insertionSort(T arr[], size_t arrSize) {
    for (size_t K = 1; K < arrSize; K++) {
        T temp = arr[K];
        int J = K - 1;
 
        while (J >= 0 && temp <= arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
    }
    
}

template <typename T>
void insertionSortRange(T arr[], int low, int high){
    for (int K = low + 1; K <= high; K++){
        T temp = arr[K];
        int J = K - 1;

        while (J >= low && temp <= arr[J]){
            arr[J + 1] = arr[J];
            J--;
        }
        arr [J+1] = temp;
    }

}

template <typename T>
void shellSort(T arr[], size_t arrSize) {
    for (size_t gap = arrSize / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < arrSize; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



#endif //SORTING_H