#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int globalValue = 0;
std::mutex mtx;

void add(int value, int delayMs) {
    
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    std::lock_guard<std::mutex> lock(mtx);
    globalValue += value;
}

void display(const std::string &label) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << label << globalValue << std::endl;
}

int main() {
    std::thread t1(add, 10, 100);
    std::thread t2(add, 20, 300);
    std::thread t3(add, 30, 500);

    display("Before any join : ");
    t1.join();
    display("After T1.join() : ");
    t2.join();
    display("After T2.join() : ");
    t3.join();
    display("After T3.join() : ");

    return 0;
}