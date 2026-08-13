#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack1;
    std::stack<int> stack2;
    std::cout << "Testing stack STL" << std::endl;
    std::cout << "Checking if the stack is empty\n" << stack1.empty() << std::endl;
    std::cout << "Checking if the stack is empty\n" << stack2.empty() << std::endl;

    // Push Stack Function
    stack1.push(5);
    std::cout << "The current top: " << stack1.top() << std::endl;
    stack1.push(4);
    std::cout << "The current top: " << stack1.top() << std::endl;
    stack1.push(3);
    std::cout << "The current top: " << stack1.top() << std::endl;
    stack1.push(2);
    std::cout << "The current top: " << stack1.top() << std::endl;
    stack1.push(1);
    std::cout << "The current top: " << stack1.top() << std::endl;

    // Pop Stack Fuction
    std::cout << "\nPopping top of stack" << std::endl;
    stack1.pop();
    std::cout << "The current top: " << stack1.top() << std::endl;
    std::cout << "Checking if the stack is empty: " << stack1.empty() << std::endl;

    // Size of Stack function
    std::cout << "The current size of the stack: " << stack1.size() << "\n" << std::endl;

    // Emplace function
    std::cout << "\nEmplacing on top of stack" << std::endl;
    stack1.emplace(10);
    std::cout << "The current top: " << stack1.top() << "\n" << std::endl;

    // Swap function
    stack2.push(6);
    std::cout << "The current top of stack 2: " << stack2.top() << std::endl;
    stack2.push(8);
    std::cout << "The current top of stack 2: " << stack2.top() << std::endl;
    stack2.push(20);
    std::cout << "The current top of stack 2: " << stack2.top() << std::endl;
    std::cout << "Swapping contents of stack 1 and 2: "<< std::endl;
    stack1.swap(stack2);
    std::cout << "The current top of stack 1: " << stack1.top() << std::endl;
    std::cout << "The current top of stack 2: " << stack2.top() << "\n" << std::endl;
    std::cout << "The current size of stack 1: " << stack1.size() << std::endl;
    std::cout << "The current size of stack 2: " << stack2.size() << std::endl;
    

    return 0;
}