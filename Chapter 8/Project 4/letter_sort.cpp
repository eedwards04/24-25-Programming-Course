#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

int main() {
    string firstName, middleName, lastName, go_again;
    do {
    cout << "Enter your full name (First [Middle/Initial] Last): ";
    
    string fullName;
    getline(cin, fullName);
    stringstream ss(fullName);

    ss >> firstName;
    string nextPart;
    ss >> nextPart;

    if (ss >> lastName) {
        middleName = nextPart;
    } else {
        lastName = nextPart;
    }

    cout << "\nFormatted name: ";
    cout << lastName << ", " << firstName;

    if (!middleName.empty()) {
        cout << " " << middleName[0] << ".";
    }

    cout << endl;
    cout << "Would you like to go again?\n";
    cin >> go_again;
    middleName = "";
    firstName = "";
    lastName = "";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (go_again == "y" || go_again == "Y");
    return 0;
}
