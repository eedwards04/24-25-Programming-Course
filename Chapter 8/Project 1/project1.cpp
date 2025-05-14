#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

int main() {
    string input, output, go_again;
    do {
        cout << "Enter a sentence (up to 100 characters). Press Enter twice to finish:\n";

        input.clear(); // Clear the input string for each iteration
        string line;
        while (true) {
            getline(cin, line);
            if (line.empty()) break; // Stop reading when an empty line is entered
            input += line + " "; // Append the line to input with a space
        }

        if (input.length() > 100) {
            cout << "Error: Input exceeds 100 characters. Please try again.\n";
            continue; // Restart the loop
        }

        bool capitalizeFirst = true;
        bool inSpace = false;
        output.clear(); // Clear the output string for each iteration

        for (char ch : input) {
            if (isspace(ch)) {
                if (!inSpace) {
                    output += ' ';
                    inSpace = true;
                }
            } else {
                if (capitalizeFirst) {
                    output += toupper(ch);
                    capitalizeFirst = false;
                } else {
                    output += tolower(ch);
                }
                inSpace = false;
            }
        }

        if (!output.empty() && output.back() == ' ') {
            output.pop_back(); 
        }

        if (!output.empty() && output.back() != '.') {
            output += '.';
        }


        cout << "\nCorrected sentence:\n" << output << endl;
        cout << "Would you like to go again? (y/n): ";
        cin >> go_again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    } while (go_again == "y" || go_again == "Y");
    return 0;
}