// csv_loader.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter CSV filename (e.g., dataset.csv): ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << "\n";
        return 1;
    }

    string header;
    if (!getline(file, header)) {
        cerr << "Empty file or read error.\n";
        return 1;
    }

    cout << "Header: " << header << "\n";

    string line;
    int count = 0;
    const int maxEntries = 10;
    while (getline(file, line) && count < maxEntries) {
        vector<string> fields;
        string token;
        stringstream ss(line);

        // Simple CSV split on commas (does not handle embedded commas with quotes).
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }

        // Ensure at least 5 fields; if not, pad with empty strings
        fields.resize(max(5, (int)fields.size()));

        cout << "\nEntry " << (count + 1) << ":\n";
        cout << "Field 1: " << fields[0] << "\n";
        cout << "Field 2: " << fields[1] << "\n";
        cout << "Field 3: " << fields[2] << "\n";
        cout << "Field 4: " << fields[3] << "\n";
        cout << "Field 5: " << fields[4] << "\n";

        // If you want, parse more fields here.
        ++count;
    }

    cout << "\nLoaded " << count << " entries (up to " << maxEntries << ").\n";
    file.close();
    return 0;
}
