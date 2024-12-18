#include <iostream>
#include <string>
using namespace std;

bool is_leap_year(int year);
int get_century_value(int year);
int get_year_value(int year);
int get_month_value(int month, int year);
void get_input(int& day, int& month, int& year);
string get_day_of_week(int day, int month, int year);

int main() {
    string go_again;
    do {
        int day, month, year;
        get_input(day, month, year);

        string day_of_week = get_day_of_week(day, month, year);
        cout << "The day of the week is: \n" << day_of_week << endl;
        cout << "Would you like to go again (y/n): ";
        cin >> go_again;
    } while (go_again == "Y" || go_again == "y");

    return 0;
}

bool is_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

int get_century_value(int year) {
    year = year / 100;
    int remainder = year % 4;
    int multiplier = 3 - remainder;
    return multiplier * 2;
}

int get_year_value(int year) {
    int last_digits = year % 100;
    int leap_year = last_digits / 4;
    return leap_year + last_digits;
}

int get_month_value(int month, int year) {
    int month_values[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

    if (is_leap_year(year)) {
        month_values[0] = 6; // Jan
        month_values[1] = 2; // Feb
    }

    if (month < 1 || month > 12)
        return -1;

    return month_values[month - 1]; // Subtract 1 to convert 1-12 to 0-11 array index
}

string get_day_of_week(int day, int month, int year) {
    int month_value = get_month_value(month, year);
    int year_value = get_year_value(year);
    int century_value = get_century_value(year);

    int total = day + month_value + year_value + century_value;

    int day_of_week_num = total % 7;

    string day_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return day_names[day_of_week_num];
}

void get_input(int& day, int& month, int& year) {
    bool valid_input = false;
    while (!valid_input) {
        cout << "Enter the day of the month (1-31): \n";
        cin >> day;
        if (day < 1 || day > 31) {
            cout << "Invalid day! Please enter a valid day (1-31).\n";
            continue;  // Ask for the day again if invalid
        }

        cout << "Enter the month (1-12): \n";
        string month_input;
        cin >> month_input;

        // Convert month input to a number if it's a string
        if (month_input == "1") {
            month = 1;
        } else if (month_input == "2") {
            month = 2;
        } else if (month_input == "3") {
            month = 3;
        } else if (month_input == "4") {
            month = 4;
        } else if (month_input == "5") {
            month = 5;
        } else if (month_input == "6") {
            month = 6;
        } else if (month_input == "7") {
            month = 7;
        } else if (month_input == "8") {
            month = 8;
        } else if (month_input == "9") {
            month = 9;
        } else if (month_input == "10") {
            month = 10;
        } else if (month_input == "11") {
            month = 11;
        } else if (month_input == "12") {
            month = 12;
        } else {
            cout << "Invalid month input! Please enter a valid month (1-12).\n";
            continue;  // Ask for the month again if it's invalid
        }

        // Now check if the day is valid for the given month
        if ((month == 2 && day > 29) || (month == 4 || month == 6 || month == 9 || month == 11) && day > 30 || day > 31) {
            cout << "Invalid day for the given month! Please enter a valid day.\n";
            continue;  // Ask for the day again if it's invalid
        }

        // If we reached here, inputs are valid
        valid_input = true;

        cout << "Enter the year: \n";
        cin >> year;
    }
}
