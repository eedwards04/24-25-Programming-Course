#include <iostream>
using namespace std;


bool containsInvalidDigits(const string &temp) {
    return temp.find('1') != string::npos ||
           temp.find('4') != string::npos ||
           temp.find('7') != string::npos;
}
int main() {
    string temp_input;
    int temp;
    cout<<"What is your desired temperature? \n";
    cin>>temp_input;
    temp = stoi(temp_input);
        if (containsInvalidDigits(temp_input)) {
            int larger_temp = temp;
            int smaller_temp = temp;
            do {
                larger_temp++;
            } while (containsInvalidDigits(to_string(larger_temp)));
            do {
                smaller_temp--;
            } while (containsInvalidDigits(to_string(smaller_temp)));

            cout << "The next smallest valid temperature is: " << smaller_temp << endl;
            cout << "The next largest valid temperature is: " << larger_temp << endl;
        } else {
            // If no invalid digits, print the desired temperature
            cout << "Your desired temperature of " << temp_input << " is possible!" << endl;
        }
    return 0;
}
/*//Unfortunately the circuitry is damaged and the digits in the leftmost column no longer function. In other words, the digits 1, 4, and 7 do not work.
If a recipe calls for a temperature that can’t be entered, then you would
like to substitute a temperature that can be entered. Write a program that
inputs a desired temperature. The temperature must be between 0 and 999
degrees. If the desired temperature does not contain 1, 4, or 7, then output
the desired temperature. Otherwise, compute the next largest and the next
smallest temperature that does not contain 1, 4, or 7 and output both.
For example, if the desired temperature is 450, then the program
should output 399 and 500. Similarly, if the desired temperature is
375, then the program should output 380 and 369.*/