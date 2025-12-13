#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount() { balance = 0.0; }

    void deposit(double amount) {
        balance += amount;
        saveTransaction("Deposit", amount);
    }

    void purchase(string item, double cost) {
        if (cost <= balance) {
            balance -= cost;
            saveTransaction("Purchase: " + item, cost);
        }
    }

    void displayBalance() {
        cout << "Balance: $" << balance << endl;
    }

    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        file << type << " $" << amount << endl;
        file.close();
    }
};

int main() {
    BankAccount acc;
    acc.deposit(100);
    acc.purchase("Coffee", 5);
    acc.purchase("Book", 20);
    acc.displayBalance();
    return 0;
}
