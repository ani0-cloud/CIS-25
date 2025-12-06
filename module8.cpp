// BankAccount.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    double balance;

    void saveTransaction(const string& type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << fixed << setprecision(2) << amount << "\n";
            file.close();
        }
    }

public:
    BankAccount() : balance(0.0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Deposited $" << fixed << setprecision(2) << amount << ". New balance: $" << balance << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(const string& item, double cost) {
        if (cost <= 0) {
            cout << "Invalid cost.\n";
            return;
        }
        if (cost > balance) {
            cout << "Insufficient funds for " << item << ".\n";
            saveTransaction("Failed Purchase - " + item, cost);
        } else {
            balance -= cost;
            cout << "Purchased " << item << " for $" << fixed << setprecision(2) << cost << ".\n";
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() const {
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    BankAccount myAccount;
    myAccount.deposit(100.00);
    myAccount.makePurchase("Coffee", 4.50);
    myAccount.makePurchase("Book", 25.00);
    myAccount.displayBalance();

    cout << "Transactions have been written to transactions.txt\n";
    return 0;
}
