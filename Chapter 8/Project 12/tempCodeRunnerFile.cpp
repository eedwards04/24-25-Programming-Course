#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

string convertToMilitaryTime(const string& time12hr) {
    int hour, minute;
    char colon;
    string meridian;

    stringstream ss(time12hr);
    ss >> hour >> colon >> minute >> meridian;

    if (meridian == "AM" || meridian == "am") {
        if (hour == 12) {
            hour = 0; // 12 AM is 00
        }
    } else if (meridian == "PM" || meridian == "pm") {
        if (hour != 12) {
            hour += 12; // Add 12 unless it's already 12 PM
        }
    }

    stringstream result;
    result << setfill('0') << setw(2) << hour
           << setw(2) << minute << " hours";

    return result.str();
}

int main() {
    string time12hr;
    char again;

    do {
        cout << "Enter time in 12-hour format (e.g., 1:10 AM): ";
        getline(cin, time12hr);

        string militaryTime = convertToMilitaryTime(time12hr);
        cout << "Military time: " << militaryTime << endl;

        cout << "\nConvert another time? (y/n): ";
        cin >> again;
        cin.ignore(); 
    } while (again == 'y' || again == 'Y');
}