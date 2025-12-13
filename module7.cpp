#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int id;
};

int binarySearch(Item* arr, int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].id == target)
            return mid;
        else if (arr[mid].id < target)
            left = mid + 1;
        else
            right = mid - 1;
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

    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    int result = binarySearch(inventory, size, searchId);

    if (result != -1)
        cout << "Found: " << inventory[result].name << endl;
    else
        cout << "Item not found.\n";

    delete[] inventory;
    return 0;
}
