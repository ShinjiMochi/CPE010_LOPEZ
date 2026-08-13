#include <iostream>
#include <string.h>
#include <iomanip>

class Fruit{
    private:
        std::string fruitName;
        double fruitPrice;
        int fruitQuantity;
    public:
    // Constructor
    Fruit(std::string newName = "", double newPrice = 0, int newQuantity = 0){
        fruitName = std::move(newName);
        fruitPrice = newPrice;
        fruitQuantity = newQuantity;
    };
    // Deconstructor 
    ~Fruit() { 
    }
    // Copy Constructor
    Fruit(const Fruit &copyFruit) {
        fruitName = copyFruit.fruitName;
        fruitPrice = copyFruit.fruitPrice;
        fruitQuantity = copyFruit.fruitQuantity;
    }
    //Display Attributes
    double totalSum() const {
        return fruitPrice * fruitQuantity;
    }

    void receipt() const {
        std::cout << std::left
                  << std::setw(15) << "Fruit"
                  << std::setw(15) << fruitName
                  << std::setw(12) << fruitPrice
                  << std::setw(12) << fruitQuantity
                  << std::setw(12) << totalSum()
                  << std::endl;
    }
};

class Vegetable{
    private:
        std::string vegetableName;
        double vegetablePrice;
        int vegetableQuantity;
    public:
    // Constructor
    Vegetable(std::string newName = "", double newPrice = 0, int newQuantity = 0){
        vegetableName = std::move(newName);
        vegetablePrice = newPrice;
        vegetableQuantity = newQuantity;
    };
    // Deconstructor 
    ~Vegetable() { 
    }
    // Copy Constructor
    Vegetable(const Vegetable &copyVegetable) {
        vegetableName = copyVegetable.vegetableName;
        vegetablePrice = copyVegetable.vegetablePrice;
        vegetableQuantity = copyVegetable.vegetableQuantity;
    }
    //Display Attributes
    double totalSum() const {
        return vegetablePrice * vegetableQuantity;
    }

    void receipt() const {
        std::cout << std::left
                  << std::setw(15) << "Vegetable"
                  << std::setw(15) << vegetableName
                  << std::setw(12) << vegetablePrice
                  << std::setw(12) << vegetableQuantity
                  << std::setw(12) << totalSum()
                  << std::endl;
    }
};

double totalSum(Fruit* fruits[], int fruitQuantity,
                Vegetable* vegetables[], int vegetableQuantity);

int main() {

    // Problem 2
    Fruit* fruitsTaken[2];
    Vegetable* vegetablesTaken[2];

    fruitsTaken[0] = new Fruit("Apple", 10, 7);
    fruitsTaken[1] = new Fruit("Banana", 10, 8);

    vegetablesTaken[0] = new Vegetable("Broccoli", 60, 12);
    vegetablesTaken[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "\n================ MEMORY STATUS ================\n";

    std::cout << "Apple Pointer      : " << fruitsTaken[0] << std::endl;

    std::cout << "Banana Pointer     : " << fruitsTaken[1] << std::endl;

    std::cout << "Broccoli Pointer   : " << vegetablesTaken[0] << std::endl;

    std::cout << "Lettuce Pointer    : " << vegetablesTaken[1] << std::endl;

    std::cout << "===============================================\n";

    std::cout << "============================================================\n";
    std::cout << "               JENNA'S GROCERY RECEIPT\n";
    std::cout << "============================================================\n";

    std::cout << std::left
              << std::setw(15) << "Type"
              << std::setw(15) << "Item"
              << std::setw(10) << "Price"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Total"
              << std::endl;
    std::cout << "------------------------------------------------------------\n";

    std::cout << "Fruits:" << std::endl;
    for (int i = 0; i < 2; i++) {
        fruitsTaken[i]->receipt();
    }

    std::cout << "Vegetables:" << std::endl;
    for (int i = 0; i < 2; i++) {
        vegetablesTaken[i]->receipt();
    }

    std::cout << "\nAmount to Pay (Php): "
              << totalSum(fruitsTaken, 2, vegetablesTaken, 2)
              << std::endl;

    // Problem 4
    char answer;

    std::cout << "\nProceed to Delete Lettuce? (Y/N): ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y') {

        std::cout << "\n========== POINTER LIST BEFORE DELETION ==========\n";

        std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
        std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
        std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
        std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

        std::cout << "==================================================\n";

        std::cout << "\nDeleting Lettuce...\n";

        delete vegetablesTaken[1];

        vegetablesTaken[1] = nullptr;

        std::cout << "\nMemory successfully deallocated.\n";

        std::cout << "\n========== POINTER LIST AFTER DELETION ==========\n";

        std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

        std::cout << "=================================================\n";

    if (vegetablesTaken[1] == nullptr) {
        std::cout << "\nLettuce successfully deleted.\n";
        std::cout << "Lettuce pointer is now nullptr.\n";
    }
    }
    else {
        std::cout << "\nDeletion cancelled.\n";
    }

    std::cout << "\nPress Enter to Continue...";
    std::cin.ignore();
    std::cin.get();

    std::cout << "\n============================================================\n";
    std::cout << "\t\t  UPDATED GROCERY RECEIPT\n";
    std::cout << "============================================================\n";

    std::cout << "Fruits:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitsTaken[i] != nullptr) {
            fruitsTaken[i]->receipt();
        }
    }

    std::cout << "\nVegetables:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (vegetablesTaken[i] != nullptr) {
            vegetablesTaken[i]->receipt();
        }
    }

    std::cout << "\nUdpated Amount to Pay (Php): "
              << totalSum(fruitsTaken, 2, vegetablesTaken, 2)
              << std::endl;

// Cleaning up memory to prevent memory leak.

    std::cout << "\n========== POINTER LIST BEFORE FINAL CLEANUP ==========\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "=======================================================\n";

    std::cout << "\nCleaning up remaining memory...\n";

// Delete Apple and Banana
    for (int i = 0; i < 2; i++) {
    delete fruitsTaken[i];
    fruitsTaken[i] = nullptr;
}

// Delete Broccoli
    delete vegetablesTaken[0];

    vegetablesTaken[0] = nullptr;

    std::cout << "\nMemory successfully cleaned up.\n";

    std::cout << "\n========== POINTER LIST AFTER FINAL CLEANUP ==========\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "======================================================\n";

    if (fruitsTaken[0] == nullptr &&
        fruitsTaken[1] == nullptr &&
        vegetablesTaken[0] == nullptr &&
        vegetablesTaken[1] == nullptr) {

    std::cout << "\nAll allocated memory has been deallocated successfully.\n";
}
    return 0;
}

// Problem 3 
double totalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegetableCount) {

    double total = 0;

    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != nullptr) {
            total += fruits[i]->totalSum();
        }
    }

    for (int i = 0; i < vegetableCount; i++) {
        if (vegetables[i] != nullptr) {
            total += vegetables[i]->totalSum();
        }
    }

    return total;
}