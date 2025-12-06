// MODULE 6: Strings and Classes
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file.\n";
        } else {
            cout << "Could not open file.\n";
        }
    }

    void loadFromFile() {
        ifstream in("items.txt");
        string line;
        if (in.is_open()) {
            while (getline(in, line)) {
                cout << "File content: " << line << endl;
            }
            in.close();
        } else {
            cout << "Could not read file.\n";
        }
    }
};

int main() {
    Item tool;
    tool.name = "Hammer";
    tool.quantity = 5;

    tool.saveToFile();
    tool.loadFromFile();

    return 0;
}
