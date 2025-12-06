// MODULE 7: Pointers, Struct, Binary Search
#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int id;
};

int binarySearch(Item arr[], int size, int targetID) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid].id == targetID)
            return mid;
        else if (arr[mid].id > targetID)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    int size = 100;
    Item* inventory = new Item[size];

    for (int i = 0; i < size; i++) {
        inventory[i].id = i + 1;
        inventory[i].name = "Item" + to_string(i + 1);
    }

    int target;
    cout << "Enter ID to search: ";
    cin >> target;

    int index = binarySearch(inventory, size, target);

    if (index != -1)
        cout << "Found: " << inventory[index].name << " (ID " << inventory[index].id << ")\n";
    else
        cout << "Item not found.\n";

    delete[] inventory;
    return 0;
}
