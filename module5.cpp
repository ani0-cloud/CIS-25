#include <iostream>
using namespace std;

void showMenu() {
    cout << "1. Add Item\n";
    cout << "2. View Items\n";
    cout << "3. Exit\n";
}

void addItem() {
    cout << "Item added!\n";
}

void viewItems() {
    cout << "Viewing items...\n";
}

int main() {
    int option;

    do {
        showMenu();
        cin >> option;

        if (option == 1)
            addItem();
        else if (option == 2)
            viewItems();

    } while (option != 3);

    return 0;
}
