#include <iostream>
#include <stack>

int main() {
    std::stack<int> newStack;

    // Push Stack Function
    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    // isEmpty Function
    std::cout << "Is the stack empty?: " << newStack.empty() << "\n\n";

    // Size of Stack function
    std::cout << "The current size of the stack: " << newStack.size() << "\n\n";

    // Top Function
    std::cout << "The Top of the stack: " << newStack.top() << "\n\n";

    // Pop Stack Fuction
    newStack.pop();

    std::cout << "The current size of the stack: " << newStack.size() << "\n\n";

    std::cout << "The Top of the stack: " << newStack.top() << "\n\n";
    
    return 0;
}

