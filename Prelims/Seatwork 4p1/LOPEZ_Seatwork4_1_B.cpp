#include <iostream>
#include <chrono>
#include <thread>

// global declaration
#define maxCap 100
int stackArr[maxCap];
int top = -1, newData;

// prototype function
void push();
void pop();
void Top();
void display();
bool isEmpty();
bool isFull();

// wait function
void wait();

int main(){
    // main driver code
    int choice;

    while (true){
        std::cout << "===============================================" << std::endl;
        std::cout << "Stack Operations\n";
        std::cout << "1. PUSH \t4. isEmpty\n2. POP \t\t5. isFull\n3. TOP \t\t6. Display Stack\n" << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1: push(); 
            break;
            case 2: pop();      
            break;
            case 3: Top(); 
            break;
            case 4: std::cout << "Is the stack empty? " << isEmpty() << std::endl;
            break;
            case 5: std::cout << "Is the stack full? " << isFull() << std::endl;
            system("CLS");
            break;
            case 6: display(); 
            break;
            default: std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

}

// Function Definition
void wait(int time) {
	std::this_thread::sleep_for(std::chrono::seconds(time));
}

bool isEmpty(){
    // check the top if it is -1
    if(top == -1) return true;
    return false;
}

bool isFull(){
    // how do we verify if the stack is full
    if(top == maxCap - 1) return true;
    return false;
}

void push(){
    // error checking
    if(isFull()){
        std::cout << "Stack Overflow" << std::endl;
        wait(2);
        system("CLS");
        return;
    }

    // pushing to the stack
    std::cout << "Enter a new value" << std::endl;
    std::cin >> newData;

    // how do we insert the data into the stack?
    stackArr[++top] = newData;
    wait(2);
    system("CLS");
}

void pop(){
    // Error checking
    if(isEmpty()){
        std::cout << "Stack Underflow" << std::endl;
        wait(2);
        system("CLS");
        return;
    }

    // Display the value that we are going to pop
    std::cout << "Popping: " << stackArr[top] << std::endl;

    // decrement the value from the stack
    top--;
    wait(2);
    system("CLS");

}

void Top(){
    // error catching
    if(isEmpty()){
        std::cout << "The stack is empty" << std::endl;
        wait(2);
        system("CLS");
        return;
    }

    // check the top element
    std::cout << "Top Element: " << stackArr[top] << std::endl;
    wait(2);
    system("CLS");

}

void display() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        wait(2);
        system("CLS");
        return;
    }

    std::cout << "Stack elements (top to bottom):" << std::endl;
    for (int j = top; j >= 0; j--) {
        std::cout << stackArr[j] << " ";
    }
    std::cout << std::endl;
    wait(4);
    system("CLS");
}

