#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*
  Class to represent one row from the solar energy dataset
*/
class SolarRecord {
public:
    string city;
    string country;
    double annualSunlight;
    double peakSunHours;
    double annualProduction;
    double annualSavings;
    int viabilityScore;

    // Display one record in a readable format
    void display() {
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "Annual Sunlight Hours: " << annualSunlight << endl;
        cout << "Daily Peak Sun Hours: " << peakSunHours << endl;
        cout << "Annual Production (kWh): " << annualProduction << endl;
        cout << "Annual Savings (USD): $" << annualSavings << endl;
        cout << "Solar Viability Score: " << viabilityScore << endl;
        cout << "----------------------------------\n";
    }
};

int main() {
    ifstream file("solar_energy_worldwide.csv");

    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return 1;
    }

    string line;
    getline(file, line); // Skip header row

    SolarRecord records[10];
    int count = 0;

    // Read first 10 rows from the CSV file
    while (getline(file, line) && count < 10) {
        stringstream ss(line);
        string token;

        // Column order based on CSV structure
        getline(ss, records[count].city, ',');            // City
        getline(ss, records[count].country, ',');         // Country

        getline(ss, token, ',');                           // Latitude (skip)
        getline(ss, token, ',');                           // Longitude (skip)

        getline(ss, token, ',');                           // Annual Sunlight Hours
        records[count].annualSunlight = stod(token);

        getline(ss, token, ',');                           // Daily Peak Sun Hours
        records[count].peakSunHours = stod(token);

        getline(ss, token, ',');                           // GHI (skip)
        getline(ss, token, ',');                           // Electricity price (skip)
        getline(ss, token, ',');                           // Install count (skip)
        getline(ss, token, ',');                           // Avg system cost (skip)

        getline(ss, token, ',');                           // Avg annual production
        records[count].annualProduction = stod(token);

        getline(ss, token, ',');                           // Estimated annual savings
        records[count].annualSavings = stod(token);

        getline(ss, token, ',');                           // Payback period (skip)
        getline(ss, token, ',');                           // ROI (skip)
        getline(ss, token, ',');                           // CO2 reduction (skip)

        getline(ss, token, ',');                           // Solar viability score
        records[count].viabilityScore = stoi(token);

        count++;
    }

    file.close();

    // Display loaded data
    cout << "Solar Energy Dataset (First 10 Records)\n";
    cout << "=====================================\n";

    for (int i = 0; i < count; i++) {
        records[i].display();
    }

    return 0;
}
