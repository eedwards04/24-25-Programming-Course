#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void current_time(int& hour_input, int& minute_input, char& am_pm);
void waiting_time(int& wait_hour, int& wait_minute);
void calc_time(int hour_input, int minute_input, int wait_hour, int wait_minute, char& am_pm, int& new_hour, int& new_minute);
void final_time(int new_hour, int new_minute, char am_pm);

int main()
{
    char go_again;
    do {
        int hour_input = 0, minute_input = 0, wait_hour = 0, wait_minute = 0, new_hour = 0, new_minute = 0;
        char am_pm = 'A';

        current_time(hour_input, minute_input, am_pm);
        waiting_time(wait_hour, wait_minute);
        calc_time(hour_input, minute_input, wait_hour, wait_minute, am_pm, new_hour, new_minute);
        final_time(new_hour, new_minute, am_pm);

        cout << "Would you like to make another conversion (y/n)?\n";
        cin >> go_again;

    } while (go_again == 'y' || go_again == 'Y');
    return 0;
}

void current_time(int& hour_input, int& minute_input, char& am_pm) {
    cout << "Enter the current time in a 12-hour format (HH:MM AM/PM):\n";
    char colon;
    string am_pm_str;
    cin >> hour_input >> colon >> minute_input >> am_pm_str;
    am_pm = am_pm_str[0];
}

void waiting_time(int& wait_hour, int& wait_minute) {
    cout << "Enter the number of hours you have to wait:\n";
    cin >> wait_hour;
    cout << "Enter the number of minutes you have to wait:\n";
    cin >> wait_minute;
}

void calc_time(const int hour_input, const int minute_input, const int wait_hour, const int wait_minute, char& am_pm, int& new_hour, int& new_minute) {
    new_hour = wait_hour + hour_input;
    new_minute = wait_minute + minute_input;

    if (new_minute >= 60) {
        new_minute -= 60;
        new_hour++;
    }

    if (new_hour >= 12) {
        if (new_hour > 12) new_hour -= 12;
        am_pm = (am_pm == 'A') ? 'P' : 'A';
    }

    if (new_hour == 0) {
        new_hour = 12;
    }
}

void final_time(int new_hour, int new_minute, char am_pm) {
    cout << "By the time you are done waiting it will be: ";
    cout << setw(2) << setfill('0') << new_hour << ":"
         << setw(2) << setfill('0') << new_minute << " " << am_pm << "M" << endl;
}

/*Write a program that requests the current time and a waiting time as two
integers for the number of hours and the number of minutes to wait. The
program then outputs what the time will be after the waiting period. Use
12-hour notation for the times. Include a loop that lets the user repeat this
calculation for additional input values until the user says she or he wants
to end the program.*/