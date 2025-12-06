// item_total_cost.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string itemName;
    int quantity;
    double cost;

    cout << "Enter item name: ";
    cin >> itemName; // for multi-word names, use getline if desired
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter cost (per item): ";
    cin >> cost;

    double total = quantity * cost;
    cout << fixed << setprecision(2);
    cout << "Total cost for " << itemName << ": $" << total << endl;

    return 0;
}
