// menu_with_functions.cpp
#include <iostream>
#include <string>
using namespace std;

void showMenu() {
    cout << "\n--- Main Menu ---\n";
    cout << "1. Add (simulated)\n";
    cout << "2. View (simulated)\n";
    cout << "3. Print Hello\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

void doAdd() {
    cout << "Add: (this is a placeholder function).\n";
}

void doView() {
    cout << "View: (this is a placeholder function).\n";
}

void sayHello() {
    cout << "Hello from option 3!\n";
}

int main() {
    int option;
    do {
        showMenu();
        cin >> option;
        switch (option) {
            case 1: doAdd(); break;
            case 2: doView(); break;
            case 3: sayHello(); break;
            case 4: cout << "Exiting menu.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (option != 4);

    return 0;
}
