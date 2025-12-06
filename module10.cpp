// inheritance_access_levels.cpp
#include <iostream>
using namespace std;

class User {
public:
    virtual void accessLevel() {
        cout << "General Access\n";
    }
    virtual ~User() = default;
};

class Employee : public User {
public:
    void accessLevel() override {
        cout << "Employee Access\n";
    }
};

class InventoryManager : public Employee {
public:
    void accessLevel() override {
        cout << "Full Inventory Management Access\n";
    }
};

int main() {
    InventoryManager mgr;
    mgr.accessLevel(); // should call InventoryManager::accessLevel
    return 0;
}
