#include "menu.h"
#include "doubly_ll.h"
#include <iostream>
#include <string>

const int openMenuSize = 4;

std::string openMenuItems[openMenuSize] = { 
    "Open Playlist", 
    "Add Song", 
    "Remove Song", 
    "Exit" 
};

// Global head pointer for the playlist
DoubleList<std::string>* playlist = nullptr;

// Navigation Screen
void printOpeningMenu();
void printAddMenu();
void printRemoveMenu();
void opening();

// Linked List Functions
void openPlaylist();
void addSong();
void removeSong();


// --- MAIN ENTRY POINT ---

int main() {
    while (true) {
        opening();
    }
    return 0;
}


// --- FUNCTION DEFINITIONS ---

// ------- Navigation & Screen Redraw System ------- //

void printOpeningMenu() {
    printMenu("Japanify", openMenuItems, openMenuSize);
}

void printAddMenu() {
    std::string items[] = { "Top of Playlist", "General (After a Specific Song)" };
    printMenu("ADD SONG TO", items, 2);
}

void printRemoveMenu() {
    std::string items[] = { "Top of Playlist", "General (By Song Name)" };
    printMenu("REMOVE SONG FROM", items, 2);
}

void opening() {
    int selected = 0;
    printOpeningMenu();
    selected = selection(openMenuSize, printOpeningMenu);
    
    switch (selected) {
        case 0: openPlaylist(); break;
        case 1: addSong(); break;
        case 2: removeSong(); break;
        case 3: exitProg(); break;
    }
}

// ------- Playlist Feature Logic ------- //

void openPlaylist() {
    system("CLS");
    printHeader("CURRENT PLAYLIST");
    std::cout << "\n";

    dllTravers(playlist);

    std::cout << "\n\nPress any key to return to menu...";
    while (!_kbhit()); // Waits for user input
    _getch();          // Makes sure the input doesn't buffer
}

void addSong() {
    system("CLS");
    printHeader("ADD NEW SONG");
    std::string songName;
    std::cout << "  Enter song name: ";
    std::getline(std::cin, songName);

    printAddMenu();
    int choice = selection(2, printAddMenu);
    
    system("CLS");
    
    // Insert song from HEAD
    if (choice == 0) {
        if (playlist == nullptr) {
            playlist = createnewNode(songName);
        } else {
            dllInsertHead(songName, &playlist);
        }
        std::cout << "  Added '" << songName << "'!";
        wait(2);
    } 
    // Uses GENERAL INSERT to insert song
    else if (choice == 1) {
        if (playlist == nullptr) {
            std::cout << "  Playlist is empty! Inserting song at the head\n";
            playlist = createnewNode(songName);
            wait(2);
            return;
        }

        printHeader("INSERT SONG");
        std::string targetSong;
        std::cout << "  Insert after which song name?: ";
        std::getline(std::cin, targetSong);

        // Find the target node
        DoubleList<std::string>* curr = playlist;
        while (curr != nullptr && curr->data != targetSong) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            std::cout << "  Song '" << targetSong << "' not found. Appending to end instead.\n";
            dllInsertEnd(songName, playlist);
        } else if (curr->next == nullptr) {
            // If the target is the last node, use dllInsertEnd to avoid null pointer crashes
            dllInsertEnd(songName, playlist);
        } else {
            dllGeneralInsert(songName, curr);
        }
        
        std::cout << "  Successfully placed '" << songName << "' into the list.\n";
        wait(2);
    }
}

void removeSong() {
    printRemoveMenu();
    int choice = selection(2, printRemoveMenu);
    
    system("CLS");
    if (playlist == nullptr) {
        std::cout << "\tPlaylist is empty. Nothing to remove.\n";
        wait(2);
        return;
    }

    // Removes song from HEAD
    if (choice == 0) {
        DoubleList<std::string>* temp = playlist;
        playlist = playlist->next;
        if (playlist != nullptr) {
            playlist->prev = nullptr;
        }
        std::cout << "  Removed '" << temp->data << "' from the top.\n";
        delete temp;
        wait(2);
    } 
    // Removes song from NAME
    else if (choice == 1) {
        std::string targetSong;
        printHeader("REMOVE BY NAME");
        std::cout << "\nEnter exact song name to delete: ";
        std::getline(std::cin, targetSong);

        DoubleList<std::string>* curr = playlist;
        while (curr != nullptr && curr->data != targetSong) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            std::cout << "\tSong '" << targetSong << "' not found.\n";
            wait(2);
            return;
        }

        // Adjusting pointers to unlink the node safely
        if (curr == playlist) {
            playlist = curr->next;
            if (playlist != nullptr) playlist->prev = nullptr;
        } else {
            if (curr->next != nullptr) curr->next->prev = curr->prev;
            if (curr->prev != nullptr) curr->prev->next = curr->next;
        }

        std::cout << "\tRemoved '" << targetSong << "' from the playlist.\n";
        delete curr;
        wait(2);
    }
}

