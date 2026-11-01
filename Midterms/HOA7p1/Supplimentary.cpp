#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgos.h"

const std::string canditates[] = {
    "", // Index 0 left blank so Candidate 1 aligns with index 1
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustín",
    "Deja Jayla Bañaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"
};

int main() {
    // Seed the rand num gen
    std::srand(std::time(0));

    const int array_Size = 100;
    int A[array_Size];

    // Generate an unsorted array of integers (votes) ranging from 1 to 5
    for(int i = 0; i < array_Size; i++) {
        A[i] = (std::rand() % 5) + 1; // Generates random integer 1, 2, 3, 4, or 5
    }

    std::cout << "--- Votes Generated Successfully ---\n\n";
    
    // Sort the array using Insertion Sort
    insertionSort(A, array_Size);

    // Count the votes using a searching/counting technique
    int voteCounts[6] = {0}; // Index 1 to 5 stores the votes for Candidates 1 to 5
    
    for(int i = 0; i < array_Size; i++) {
        int vote = A[i];
        voteCounts[vote]++;
    }

    // VIisualize the sorted arrays
    std::cout << "---- SORTED BLOCKS BY CANDIDATE VOTE ----\n";
    for(int candidate = 1; candidate <= 5; candidate++) {
        std::cout << "Candidate " << candidate << " Array: ";
        for(int i = 0; i < array_Size; i++) {
            if(A[i] == candidate) {
                std::cout << A[i] << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------------------\n\n";

    // Display vote tally results
    std::cout << "---- ELECTION RESULTS TALLY ----\n";
    for(int i = 1; i <= 5; i++) {
        std::cout << "Candidate " << i << " " << canditates[i] << ": " 
                  << voteCounts[i] << " votes\n";
    }
    std::cout << "--------------------------------\n\n";

    // Find the winning candidate
    int maxVotes = -1;
    int winningID = 1;
    bool tie = false;

    for(int i = 1; i <= 5; i++) {
        if(voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winningID = i;
            tie = false;
        } else if(voteCounts[i] == maxVotes) {
            tie = true; // Flag in case of a direct voting tie
        }
    }

    // Display Winner
    if(tie) {
        std::cout << "The election resulted in a tie! Highest vote count: " << maxVotes << "\n";
    } else {
        std::cout << "WINNING CANDIDATE:\n";
        std::cout << "Candidate " << winningID << ": " << canditates[winningID] 
                  << " with " << maxVotes << " total votes!\n";
    }

    return 0;
}