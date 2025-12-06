// dynamic_items_binary_search.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    int id;
};

// comparator to sort by id
bool cmpById(const Item& a, const Item& b) {
    return a.id < b.id;
}

int binarySearchById(Item* arr, int size, int targetId) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == targetId) return mid;
        if (arr[mid].id < targetId) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    const int N = 100; // minimum 100 records
    Item* inventory = new Item[N];

    // Populate with sample, sorted by id. Names are example strings.
    for (int i = 0; i < N; ++i) {
        inventory[i].id = 1000 + i; // ids 1000..1099
        inventory[i].name = "Item_" + to_string(i + 1);
    }

    // Ensure sorted (they already are, but safer to call sort if data came unsorted)
    sort(inventory, inventory + N, cmpById);

    cout << "Populated inventory with " << N << " items (ids 1000..1099)\n";
    int searchId;
    cout << "Enter ID to search for: ";
    cin >> searchId;

    int idx = binarySearchById(inventory, N, searchId);
    if (idx >= 0) {
        cout << "Found item: ID=" << inventory[idx].id
             << ", Name=" << inventory[idx].name << endl;
    } else {
        cout << "Item with ID " << searchId << " not found.\n";
    }

    delete[] inventory;
    return 0;
}
