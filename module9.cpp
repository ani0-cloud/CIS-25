// inventory_array.cpp
#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;
};

void displayItems(Item items[], int size) {
    cout << "\nCurrent Inventory:\n";
    for (int i = 0; i < size; ++i) {
        cout << i+1 << ". " << items[i].name << " - Qty: " << items[i].quantity << "\n";
    }
}

int findItemByName(Item items[], int size, const string& searchName) {
    for (int i = 0; i < size; ++i) {
        if (items[i].name == searchName) return i;
    }
    return -1;
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter name for item " << i+1 << ": ";
        cin >> inventory[i].name;
        cout << "Enter quantity: ";
        cin >> inventory[i].quantity;
    }

    displayItems(inventory, SIZE);

    string query;
    cout << "\nEnter a name to search: ";
    cin >> query;
    int idx = findItemByName(inventory, SIZE, query);
    if (idx != -1) {
        cout << "Found " << inventory[idx].name << " with quantity " << inventory[idx].quantity << endl;
    } else {
        cout << "Item not found.\n";
    }

    return 0;
}
