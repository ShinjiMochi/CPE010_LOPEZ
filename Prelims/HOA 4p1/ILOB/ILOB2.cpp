#include <iostream>
#include "ILOB2.h"

int main() {
    
    std::cout << "--- PUSHING 'S' 'H' 'I' 'N' ONTO THE STACK ---\n";

    // Pushing Chars
    push('S');
    push('H');
    push('I');
    push('N');

    // Display the top

    Top<char>; // Top element is N
    displayALL<char>();
    std::cout << "\n --- Popping Elements ---\n";

    while(!isEmpty<char>()) {
        std::cout<<"Popped: "<< pop<char>() <<std::endl;
    }

    std::cout << "\n --- Checking for Underflow Condition --- \n";
    pop<char>(); 

    return 0;
}