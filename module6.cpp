// Item_class_fileio.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item() : name(""), quantity(0) {}
    Item(const string& n, int q) : name(n), quantity(q) {}

    void saveToFile(const string& filename = "items.txt") {
        ofstream out(filename, ios::app); // append mode
        if (out.is_open()) {
            out << name << "," << quantity << "\n";
            out.close();
            cout << "Item saved to file: " << name << "," << quantity << endl;
        } else {
            cout << "Unable to open file for writing.\n";
        }
    }

    static void loadFromFile(const string& filename = "items.txt") {
        ifstream in(filename);
        if (in.is_open()) {
            string line;
            cout << "--- items.txt contents ---\n";
            while (getline(in, line)) {
                cout << line << "\n";
            }
            in.close();
        } else {
            cout << "Unable to open file for reading.\n";
        }
    }
};

int main() {
    Item tool;
    cout << "Enter item name: ";
    cin >> tool.name;
    cout << "Enter quantity: ";
    cin >> tool.quantity;

    tool.saveToFile();
    Item::loadFromFile();

    return 0;
}
