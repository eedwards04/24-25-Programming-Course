#include <iostream>
#include <set>
using namespace std;

void extractDigits(int number, int digits[]) {
    digits[0] = number / 1000;
    digits[1] = (number / 100) % 10;
    digits[2] = (number / 10) % 10;
    digits[3] = number % 10;
}

bool areDigitsUnique(int digits[]) {
    set<int> uniqueDigits;
    for (int i = 0; i < 4; i++) {
        if (uniqueDigits.count(digits[i]) > 0) {
            return false;
        }
        uniqueDigits.insert(digits[i]);
    }
    return true;
}

int main() {
    for (int number = 1000; number <= 9999; ++number) {
        int digits[4];
        extractDigits(number, digits);

        if (!areDigitsUnique(digits)) {
            continue;
        }

        if (digits[0] != 3 * digits[2]) {
            continue;
        }

        if (digits[3] % 2 == 0) {
            continue;
        }

        if (digits[0] + digits[1] + digits[2] + digits[3] != 27) {
            continue;
        }

        // If all conditions are satisfied, print the number
        cout << "The Riddler's address is: " << number << endl;
    }

    return 0;
}


/*//Holy digits Batman! The Riddler is planning his next caper somewhere on Pennsylvania Avenue.
In his usual sporting fashion, he has left the address in the form of a puzzle.
The address on Pennsylvania is a four-digitnumber where:
    • All four digits are different
    • The digit in the thousands place is three times the digit in the tens place
    • The number is odd
    • The sum of the digits is 27
Write a program that uses a loop(or loops) to find the address where the
Riddler plans to strike*/