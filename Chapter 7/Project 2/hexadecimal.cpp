#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Convert a single hex character to its integer value
int hexCharToInt(char c) {
    if (isdigit(c)) return c - '0';
    return tolower(c) - 'a' + 10;
}

// Convert an integer (0-15) to its hex character
char intToHexChar(int n) {
    if (n < 10) return '0' + n;
    return 'a' + (n - 10);
}

// Function to add two hex numbers stored as strings
bool addHex(const char* hex1, const char* hex2, char* result) {
    int len1 = strlen(hex1);
    int len2 = strlen(hex2);
    int maxLen = max(len1, len2);
    
    if (maxLen > 10) return false; // input overflow

    char tempResult[12] = {}; // to hold result + possible carry
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? hexCharToInt(hex1[i--]) : 0;
        int digit2 = (j >= 0) ? hexCharToInt(hex2[j--]) : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 16;
        tempResult[k++] = intToHexChar(sum % 16);
    }

    if (k > 10) return false; // result overflow

    // Reverse the result to get the correct order
    for (int m = 0; m < k; ++m) {
        result[m] = tempResult[k - m - 1];
    }
    result[k] = '\0';
    return true;
}

int main() {
    const int SIZE = 12; // 10 digits max + '\0'
    char hex1[SIZE], hex2[SIZE], result[SIZE];
    char choice;

    do {
        cout << "\nEnter first hexadecimal number (up to 10 digits): ";
        cin >> hex1;
        cout << "Enter second hexadecimal number (up to 10 digits): ";
        cin >> hex2;

        if (!addHex(hex1, hex2, result)) {
            cout << "Addition Overflow" << endl;
        } else {
            cout << "Result: " << result << endl;
        }

        cout << "Do you want to add another pair? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    cout << "Program ended." << endl;
    return 0;
}
