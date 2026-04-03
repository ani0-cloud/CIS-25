// MODULE 9: Inventory with Arrays
#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;
};

int searchItem(Item arr[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (arr[i].name == target)
            return i;
    }
    return -1;
}

int main() {

    const int SIZE = 5;
    Item items[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter name for item " << i + 1 << ": ";
        cin >> items[i].name;
        cout << "Enter quantity: ";
        cin >> items[i].quantity;
    }

    cout << "\nInventory:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << items[i].name << " - Qty: " << items[i].quantity << endl;
    }

    string target;
    cout << "\nSearch item by name: ";
    cin >> target;

    int index = searchItem(items, SIZE, target);

    if (index != -1)
        cout << "Found! Quantity: " << items[index].quantity << endl;
    else
        cout << "Item not found.\n";

    return 0;
}
