#include <iostream>
#include <string>

using namespace std;

string toRoman(int year) {
    const string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; ++i) {
        while (year >= values[i]) {
            result += roman[i];
            year -= values[i];
        }
    }
    return result;
}

int main() {
    int year;
    char repeat;

    do {
        cout << "Enter a year between 1000 and 3000: \n";
        cin >> year;

        if (year >= 1000 && year <= 3000) {
            string romanYear = toRoman(year);
            cout << "The year " << year << " in Roman numerals is: \n" << romanYear << endl;
        } else {
            cout << "Please enter a valid year between 1000 and 3000.\n" << endl;
        }

        cout << "Do you want to convert another year? (y/n): \n";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
//M = 1000
//D = 500
//C = 100
//L = 50
//X = 10
//V = 5
//I = 1
//Write a program that accepts a year written as a four-digit Arabic (ordinary)
//numeral and outputs the year written in Roman numerals. Important
//Roman numerals are V for 5, X for 10, L for 50, C for 100, D for 500, and M
//for 1,000. Recall that some numbers are formed by using a kind of
//subtraction of one Roman “digit”; for example, IV is 4 produced as V minus I, XL
//is 40, CM is 900, and so on. A few sample years: MCM is 1900, MCML is
//1950, MCMLX is 1960, MCMXL is 1940, MCMLXXXIX is 1989. Assume the
//year is between 1000 and 3000. Your program should include a loop that
//lets the user repeat this calculation until the user says she or he is done.