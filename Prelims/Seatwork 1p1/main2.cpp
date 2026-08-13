#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <string>

using namespace std;

void printItems(const map<string,int> &items){
    cout << "----------------------------------------------------" << endl;
	cout << "\t\t   ITEMS FOR SALE\t" << endl;
	cout << "----------------------------------------------------" << endl;
    cout << "\tItem\t\t\t Price" << endl;
	cout << "----------------------------------------------------" << endl;
    for (const auto& item: items){
        cout << "  " << item.first << ":\t" << item.second << endl;
    }
}

int itemSelection(const map<string,int> &items, vector<string>& itemNames,int curIndex) {
    string itemName;
    cout << "Input name of item to purchase: ";
    getline(cin >> ws, itemName);

    auto it = items.find(itemName); 

    if (it != items.end()) {
        cout << "Purchased " << itemName << "\n";
        itemNames[curIndex] = itemName;
        return it->second;
    }

    cout << "Item not found, please try again.\n";
    return itemSelection(items, itemNames, curIndex);
}

int main() {

    int itemAmount = 0;
    int userPayment = 0;
    int tot_Item = 0;
    
    map<string,int> items = {
        {"Playstation 5 Digital Ed.",600},
        {"Playstation 5 Disc Edition",650},
        {"White DualSense 5 Controller",75},
        {"Playstation 5 30th Aniv. Ed.",500},
        {"Dualsense 5 30th Aniv. Ed.",80},
    };

    cout << "Hello User!" << endl;
    printItems(items);
    
    cout << "\nHow many items would you like to purchase?: " << endl;
    cin >> itemAmount;
    
    vector<string> itemNames(itemAmount);

    for (int i = 0; i < itemAmount; i++) {
        int itemCost = itemSelection(items, itemNames, i);
        tot_Item += itemCost;
        cout << "Added ammount of " << itemCost << "$ to total cost\n";
    }

    cout << "\n----------------------------------------------------" << endl;
    cout << "\t\t Items in cart" << endl;

    for (int i = 0; i < itemAmount; i++) {
        cout << itemNames[i] << '\n';
    }

    cout << "\n----------------------------------------------------" << endl;
    cout << "\t Total Cost: " << tot_Item << endl;
    cout << "\t Amount to pay: " << endl;
    cin >> userPayment;
    cout << "----------------------------------------------------" << endl;

    if (userPayment >= tot_Item){
        cout << "User paid " << userPayment << "$. User's change is " << userPayment - tot_Item << "$";
    }
    else {
        cout << "User does not have enough for payment, Items were returned";
    }
    
    return 0;
}