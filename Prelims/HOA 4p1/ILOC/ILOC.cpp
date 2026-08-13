#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Global 
#define maxCap 10

const size_t arrSize = 10;
char stackArr[maxCap];
char newData;
int top = -1;

// Function Prototyping
void wait();
void push();
void pop();
void Top();
bool checkBalanced();
bool isEmpty();
bool isFull();
void display();

int main() {

    int choice;

    while(true){
        std::cout << "===============================================" << std::endl;
        std::cout << "Stack Operations\n";
        std::cout << "1. PUSH \t4. isEmpty\n2. POP \t\t5. isFull\n3. TOP \t\t6. Display Stack\n7. Check if Balanced" << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1: push(); break;
            case 2: pop();  break;
            case 3: Top();  break;
            case 4: std::cout << "Is the stack empty? " << isEmpty() << std::endl; break;
            case 5: std::cout << "Is the stack full? " << isFull() << std::endl;
            system("CLS");
            break;
            case 6: display(); break;
            case 7: checkBalanced(); break;
            default: std::cout << "Invalid choice" << std::endl; break;
        }
    }
}

// Function Definition

void wait(int time) {
	std::this_thread::sleep_for(std::chrono::seconds(time));
}

bool checkBalanced() {

    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < numExpressions; i++) {

        top = -1;              // Reset stack
        bool valid = true;

        std::string expr = expressions[i];

        for (int j = 0; j < expr.length(); j++) {

            char ch = expr[j];

            // Push opening symbols
            if (ch == '(' || ch == '{' || ch == '[') {
                stackArr[++top] = ch;
            }

            // Process closing symbols
            else if (ch == ')' || ch == '}' || ch == ']') {

                if (isEmpty()) {
                    valid = false;
                    break;
                }

                char open = stackArr[top--];

                if ((open == '(' && ch != ')') ||
                    (open == '{' && ch != '}') ||
                    (open == '[' && ch != ']')) {
                    valid = false;
                    break;
                }
            }
        }

        // Check for remaining opening symbols
        if (!isEmpty())
            valid = false;

        // Display result
        std::cout << expr << " | "
                  << (valid ? "VALID" : "INVALID")
                  << " |" << std::endl;
    }

    wait(5);
    system("CLS");
    return true;
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