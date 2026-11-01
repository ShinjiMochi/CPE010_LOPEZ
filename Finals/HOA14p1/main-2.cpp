#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

int linearSearch(const std::vector<int>& arr, int key){
    for (int i = 0; i < (int)arr.size(); i++){
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int key){
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    const int sizes[3] = {1000, 10000, 100000};
    const int runs = 1000;          
    volatile int sink = 0;          

    std::cout << std::left << std::setw(14) << "Input Size (N)"
              << std::setw(28) << "Binary Search"
              << "Linear Search \n";

    for (int n : sizes){
        
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;

        int key = -1;

        auto s1 = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < runs; r++) sink = binarySearch(arr, key);
        auto e1 = std::chrono::high_resolution_clock::now();

        auto s2 = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < runs; r++) sink = linearSearch(arr, key);
        auto e2 = std::chrono::high_resolution_clock::now();

        double binNs = std::chrono::duration_cast<std::chrono::nanoseconds>(e1 - s1).count() / (double)runs;
        double linNs = std::chrono::duration_cast<std::chrono::nanoseconds>(e2 - s2).count() / (double)runs;

        std::cout << std::left << std::setw(14) << n
                  << std::setw(28) << binNs
                  << linNs << "\n";
    }
    return 0;
}