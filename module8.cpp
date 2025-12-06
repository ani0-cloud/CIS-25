// MODULE 8: Bank Account Simulation
#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
        } else {
            balance -= cost;
            cout << "Purchased: " << item << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {

    BankAccount acc;

    acc.deposit(150);
    acc.makePurchase("Coffee", 5.5);
    acc.makePurchase("Shoes", 45);
    acc.displayBalance();

    return 0;
}
