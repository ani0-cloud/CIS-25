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
        out << name << "," << quantity << endl;
        out.close();
    }

    void loadFromFile() {
        ifstream in("items.txt");
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
};

int main() {
    Item tool;
    tool.name = "Screwdriver";
    tool.quantity = 10;

    tool.saveToFile();
    tool.loadFromFile();

    return 0;
}
