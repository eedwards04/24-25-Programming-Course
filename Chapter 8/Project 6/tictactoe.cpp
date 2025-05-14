#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int MAX_LENGTH = 100;

bool isWordChar(char ch) {
    return isalpha(ch) || isdigit(ch);
}

int main() {
    string line;
    char repeat;

    do {
        // Get valid input
        do {
            cout << "Enter a line of text (max " << MAX_LENGTH << " characters):\n";
            getline(cin, line);

            if (line.length() > MAX_LENGTH) {
                cout << "Error: Input is too long. Please enter a line with "
                     << MAX_LENGTH << " characters or fewer.\n";
            }
        } while (line.length() > MAX_LENGTH);

        string output;
        int i = 0;

        while (i < line.size()) {
            if (isdigit(line[i])) {
                int start = i;
                // Find full digit sequence
                while (i < line.size() && isdigit(line[i])) {
                    i++;
                }

                // Check characters before and after the digit sequence
                bool beforeIsWord = (start > 0 && isWordChar(line[start - 1]));
                bool afterIsWord = (i < line.size() && isWordChar(line[i]));

                if (beforeIsWord || afterIsWord) {
                    // Preserve original digits
                    output += line.substr(start, i - start);
                } else {
                    // Replace digits with '#'
                    output.append(i - start, '#');
                }
            } else {
                output += line[i++];
            }
        }

        cout << "\nModified line:\n" << output << endl;

        cout << "\nDo you want to enter another line? (y/n): ";
        cin >> repeat;
        cin.ignore(); // clear leftover newline
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
