// MODULE 5: Functions and Loops
#include <iostream>
using namespace std;

void addItem() {
    cout << "Adding item...\n";
}
void viewItem() {
    cout << "Viewing items...\n";
}
void exitProgram() {
    cout << "Exiting program...\n";
}

void showMenu() {
    cout << "\n1. Add\n2. View\n3. Exit\n";
}

int main() {

    int option;

    do {
        showMenu();
        cin >> option;

        if (option == 1)
            addItem();
        else if (option == 2)
            viewItem();
        else if (option == 3)
            exitProgram();
        else
            cout << "Invalid option.\n";

    } while (option != 3);

    return 0;
}
