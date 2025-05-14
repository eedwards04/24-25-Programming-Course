#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <limits>
using namespace std;

bool isDelimiter(char ch) {
    return isspace(ch) || ch == '.' || ch == ',';
}

int main() {
    string line, go_again;
    do {
    cout << "Enter a line of text:\n";
    getline(cin, line);

    map<char, int> letterCount;
    int wordCount = 0;
    bool inWord = false;

    for (char ch : line) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            letterCount[lower]++;
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else if (isDelimiter(ch)) {
            inWord = false;
        }
    }

    cout << "\n" << wordCount << " words" << endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (letterCount[c] > 0) {
            cout << letterCount[c] << " " << c << endl;
        }
    }
    cout << "Would you like to go again?\n";
    cin >> go_again;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    } while (go_again == "y" || go_again == "Y");

    return 0;
}

