// Product_ctor_dtor.cpp
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    Product(int i, const string& n, float p) : id(i), name(n), price(p) {
        cout << "Constructor called for product: " << name << endl;
    }

    ~Product() {
        cout << "Destructor called for product: " << name << endl;
    }

    void printDetails() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

int main() {
    Product p(101, "Notebook", 4.99f);
    p.printDetails();
    // destructor will run at end of scope
    return 0;
}
