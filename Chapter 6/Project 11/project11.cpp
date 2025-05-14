#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void userInput(string &userValueN, string &userValueM, string &userValueP);
void replacePlaceholders(const string &newFile, const string &filename, const string &valueN, const string &valueM, const string &valueP, 
                         const string &valueB, const string &valueG, const string &valueR);
void setYValues(const string &valueN, const string &valueM, const string &valueP, 
                string &userValueB, string &userValueG, string &userValueR);

int main() {
    string go_again;
    do {
    string userValueN, userValueM, userValueP;
    string userValueB, userValueG, userValueR; // Y-coordinates
    string filename = "C:\\Users\\ellae\\OneDrive\\Documents\\rectline.svg";
    string newFile = "C:\\Users\\ellae\\OneDrive\\Documents\\rectline - Copy.svg";

        userInput(userValueN, userValueM, userValueP);
        setYValues(userValueN, userValueM, userValueP, userValueB, userValueG, userValueR);
        replacePlaceholders(newFile, filename, userValueN, userValueM, userValueP, userValueB, userValueG, userValueR);

        cout << "Would you like to go again? (y/n}: ";
        cin >> go_again;
    } while (go_again == "y" || go_again == "Y");
    return 0;

}

// Function to get user input and ensure it's valid
void userInput(string &userValueN, string &userValueM, string &userValueP) {
    while (true) {
        cout << "Enter three positive numeric values for #N#, #M#, and #P#: ";
        cin >> userValueN >> userValueM >> userValueP;

        try {
            double numN = stod(userValueN);
            double numM = stod(userValueM);
            double numP = stod(userValueP);

            if (numN > 0 && numM > 0 && numP > 0) {
                break; // Valid input, exit loop
            }
            cout << "Values must be positive. Try again.\n";
        } catch (invalid_argument&) {
            cout << "Invalid input. Please enter numeric values.\n";
        }
    }
}

// Function to replace placeholders in the SVG file
void replacePlaceholders(const string &newFile, const string &filename, const string &valueN, const string &valueM, const string &valueP, 
                         const string &valueB, const string &valueG, const string &valueR) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading.\n";
        return;
    }
    ofstream outFile(newFile);
    if(!outFile) {
        cerr << "Error opening new file.\n";
        return;
    }

    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    // Replace placeholders
    content.replace(content.find("#N#"), 3, valueN);
    content.replace(content.find("#M#"), 3, valueM);
    content.replace(content.find("#P#"), 3, valueP);
    content.replace(content.find("#BY#"), 4, valueB);
    content.replace(content.find("#GY#"), 4, valueG);
    content.replace(content.find("#RY#"), 4, valueR);

    outFile << content;
    outFile.close();
}

// Function to set Y-coordinates based on input values
void setYValues(const string &valueN, const string &valueM, const string &valueP, 
                string &userValueB, string &userValueG, string &userValueR) {
    double mathValueN = stod(valueN);
    double mathValueM = stod(valueM);
    double mathValueP = stod(valueP);

    // Calculate Y-values (400 - height of bars)
    double valueB = 400 - mathValueN;
    double valueG = 400 - mathValueM;
    double valueR = 400 - mathValueP;

    // Convert to string for replacement
    userValueB = to_string((int)valueB); // Convert to int to remove decimal places
    userValueG = to_string((int)valueG);
    userValueR = to_string((int)valueR);
}
