#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;
};

int main() {
    Item inventory[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter item name: ";
        cin >> inventory[i].name;
        cout << "Enter quantity: ";
        cin >> inventory[i].quantity;
    }

    cout << "\nInventory:\n";
    for (int i = 0; i < 5; i++) {
        cout << inventory[i].name << ": "
             << inventory[i].quantity << endl;
    }

    string search;
    cout << "Search item: ";
    cin >> search;

    for (int i = 0; i < 5; i++) {
        if (inventory[i].name == search)
            cout << "Quantity: " << inventory[i].quantity << endl;
    }

    return 0;
}
