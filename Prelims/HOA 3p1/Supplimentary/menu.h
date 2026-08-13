#ifndef MISC_HPP
#define MISC_HPP

#include <iostream> //input output
#include <iomanip> //formatting
#include <vector> //vector
#include <string> //string funcions
#include <sstream> // breaking strings 
#include <conio.h>  // For _kbhit() and _getch()
#include <thread> // for wait function
#include <chrono> // for wait function	


void wait(int time);
void printHeader(const std::string &title);
void printMenu(const std::string &menuName,const std::string menuItems[],int numItems);
int selection(int menuItems,void (*printFunc)());
void exitProg();

void RemoveMenu();
void AddMenu();

int currRow = 0;

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
    std::cout << "======================================\n";
    std::cout << "\t" << title << "\n";
    std::cout << "======================================\n";
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