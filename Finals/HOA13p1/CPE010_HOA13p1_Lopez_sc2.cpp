#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

int minSteps(int n) {
    std::vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;                          // subtract 1
        if (i % 2 == 0) dp[i] = std::min(dp[i], dp[i / 2] + 1);  // divide by 2
        if (i % 3 == 0) dp[i] = std::min(dp[i], dp[i / 3] + 1);  // divide by 3
    }
    return dp[n];
}

void worker(int id, std::vector<int> &results, int N) {
    for (int n = id; n <= N; n += 4) {
        results[n] = minSteps(n);
    }
}

int main() {
    const int N = 30000;
    std::vector<int> results(N + 1);

    // Sequential
    auto start = std::chrono::high_resolution_clock::now();
    for (int n = 1; n <= N; n++) results[n] = minSteps(n);
    auto end = std::chrono::high_resolution_clock::now();
    double seqTime = std::chrono::duration<double, std::milli>(end - start).count();

    // Multithreaded 
    start = std::chrono::high_resolution_clock::now();
    std::thread t1(worker, 1, std::ref(results), N);
    std::thread t2(worker, 2, std::ref(results), N);
    std::thread t3(worker, 3, std::ref(results), N);
    std::thread t4(worker, 4, std::ref(results), N);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    end = std::chrono::high_resolution_clock::now();
    double parTime = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Sequential time  : " << seqTime << " ms\n";
    std::cout << "Multithread time : " << parTime << " ms\n";
    std::cout << "minSteps(10)     : " << results[10] << "\n";
    return 0;
}