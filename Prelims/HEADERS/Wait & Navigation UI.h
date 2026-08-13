    #ifndef SEATWORK4P1_B
    #define SEATWORK4P1_B

    #include <iostream> //input output
    #include <iomanip> //formatting
    #include <string> //string funcions 
    #include <sstream> // breaking strings
    #include <conio.h>  // For _kbhit() and _getch()
    #include <thread> // for wait function
    #include <chrono> // for wait function	

    // Global Variables
    const size_t maxCap = 100;
    int stack[maxCap];
    int top = -1, i, newData;

    const int openMenuSize = 6;
    int currRow = 0;
    const std::string openMenuItems[openMenuSize] = {
        "Push",
        "Pop",
        "Check top",
        "Check if empty",
        "Display Stack",
        "Exit"
    };


    // Main Functions for stack
    void push();
    void pop();
    void Top();
    void display();   // New function
    bool isEmpty();
    bool isFull();

    // opening function
    void opening();

    // Misc Items for Terminal UI
    void wait(int time);
    void printHeader(const std::string &title);
    void printMenu(const std::string &menuName,const std::string menuItems[],int numItems);
    int selection(int menuItems,void (*printFunc)());
    void exitProg();

    // Function Definitions

    bool isEmpty() {
        return(top == -1);
    }

    bool isFull() {
        return(top >= i - 1);
    }

    void push() {
        if (isFull()) {
            std::cout << "Stack Overflow" << std::endl;
            
            wait(5);
            system("CLS");
            opening();
            return;
        }

        std::cout << "Enter new value: ";
        std::cin >> newData;
        stack[++top] = newData;

        wait(5);
        system("CLS");
        opening();
    }

    void Top() {
        if (isEmpty()) {
            std::cout << "Stack Underflow." << std::endl;

            wait(5);
            system("CLS");
            opening();
            return;
        }

        std::cout << "The top element is: " << stack[top] << std::endl;

        wait(5);
        system("CLS");
        opening();
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow." << std::endl;

            wait(5);
            system("CLS");
            opening();
            return;
        }

        std::cout << "Popping: " << stack[top] << std::endl;
        top--;

        wait(5);
        system("CLS");
        opening();
    }

    // New function to display all elements
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        std::cout << "Stack elements (top to bottom):" << std::endl;
        for (int j = top; j >= 0; j--) {
            std::cout << stack[j] << " ";
        }
        std::cout << std::endl;

        wait(5);
        system("CLS");
        opening();
    }

    // ------------------------------------------------------------------------------ //

    // ------- Menu Function ------- //

    void printOpeningMenu() {
        printMenu("Stack Operations", openMenuItems, openMenuSize);
    }

    void opening() {
        int selected = 0;
        printOpeningMenu();
        selected = selection(openMenuSize, printOpeningMenu);
        switch (selected) {
            case 0: push(); break;
            case 1: pop();  break;
            case 2: Top(); break;
            case 3: std::cout << isEmpty() << std::endl;   break;
            case 4: display(); break;  // Call display()
            case 5: exitProg(); break;
        }
    }
    // ------------------------------------------------------------------------------ //

    // ------- Wait Function ------- //

    void wait(int time) {
        std::this_thread::sleep_for(std::chrono::seconds(time));
        //remove key inputs made while waiting
        while (kbhit()){
            getch();
        }

    }

    // ------- Header Format ------- //

    void printHeader(const std::string &title) {
        std::cout << "\n====================================\n";
        std::cout << std::setw(19) << title << "\n";
        std::cout << "====================================\n";
    }

    // ------- Navigation Function ------- //

    void printMenu(const std::string &menuName,const std::string menuItems[],int numItems){
        system("CLS");
        std::cout << "===== "<< menuName << " =====\n\n";
        for (int i = 0; i < numItems; i++) {
            if (i == currRow){
                std::cout << " " << char(249) << " " << menuItems[i] << std::endl;
            }
            else{
                std::cout << "   " << menuItems[i] << std::endl;
            }    
        }
        std::cout << "\nUse UP/DOWN arrows to navigate. Press ENTER to select.\n\n";
    }

    int selection(int menuItems,void (*printFunc)()){
        int returnedRow;
        while (true) {
            //Gets keyboard input
            if (_kbhit()) {
                int ch = _getch(); //Gets the character
                if (ch == 0 || ch == 224) {
                    ch = _getch();//Interprets the character
                    switch (ch) {
                        case 72: currRow--; if (currRow < 0) currRow = menuItems - 1; break;//User pressed down key
                        case 80: currRow++; if (currRow >= menuItems) currRow = 0; break; //User pressed up key
                    }
                    printFunc(); //reprints the menu used as parameter
                } else if (ch == 13) {
                    returnedRow = currRow;//store the current row value
                    currRow = 0; //Reset back to zero
                    return returnedRow;
                }
            }
        }
    }

    void exitProg(){
        system("CLS");
        std::cout << "Exited Program";
        exit(0);
    }

    #endif