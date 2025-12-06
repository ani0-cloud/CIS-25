// largest_of_three.cpp
#include <iostream>
using namespace std;

int main() {
    float n1, n2, n3;
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    // Nested if style: compare n1 vs others first, then n2 vs n3
    if (n1 >= n2) {
        if (n1 >= n3) {
            cout << "Largest number: " << n1 << endl;
        } else {
            cout << "Largest number: " << n3 << endl;
        }
    } else { // n2 > n1
        if (n2 >= n3) {
            cout << "Largest number: " << n2 << endl;
        } else {
            cout << "Largest number: " << n3 << endl;
        }
    }

    return 0;
}
