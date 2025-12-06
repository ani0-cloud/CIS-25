// hello_inventory.cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello Inventory System!\n";
    cout << "\tWelcome to the inventory demo.\n\n";

    cout << "Demonstrating escape characters:\n";
    cout << "Line1\nLine2\n";
    cout << "Tabbed:\tColumn1\tColumn2\n";
    cout << "Quote: \"This is a quoted string\"\n";
    cout << "Backslash: C:\\path\\to\\file\n\n";

    cout << "Data Sizes (in bytes):\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";

    return 0;
}
