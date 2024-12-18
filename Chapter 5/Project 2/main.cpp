#include <iostream>
#include <iomanip>

using namespace std;

void current_time(int& hour_input, int& minute_input);
void waiting_time(int& wait_hour, int& wait_minute) ;
void calc_time(int hour_input, int minute_input, int wait_hour, int wait_minute, int& new_hour, int& new_minute);
void final_time(int new_hour, int new_minute);

int main()
{
    char go_again;
    do {
        int hour_input = 0, minute_input = 0, wait_hour = 0, wait_minute = 0, new_hour = 0, new_minute = 0;

        current_time(hour_input, minute_input);
        waiting_time( wait_hour,wait_minute);
        calc_time(hour_input, minute_input, wait_hour, wait_minute, new_hour, new_minute);
        final_time(new_hour, new_minute);

        cout<<"Would you like to make another conversion (y/n)?\n";
        cin>>go_again;

    } while (go_again == 'y' || go_again == 'Y');
    return 0;
}

void current_time(int& hour_input, int& minute_input) {
    cout<<"Enter the current time in a 24-hour format (HH:MM):\n";
    char colon; // gets rid of ':'

    cin >> hour_input >> colon >> minute_input;
}

void waiting_time(int& wait_hour, int& wait_minute) {
    cout<<"Enter the number of hours you have to wait:\n";
    cin>>wait_hour;
    cout<<"Enter the number of minutes you have to wait:\n";
    cin>>wait_minute;

}
//fix if hour = 0
void calc_time(const int hour_input, const int minute_input, const int wait_hour, const int wait_minute, int& new_hour, int& new_minute) {
    new_hour = wait_hour + hour_input;
    new_minute = wait_minute + minute_input;

    if (new_hour >= 24) {
        new_hour -= 24;
    } else if (new_hour < 0) {
        new_hour += 24;
    }

    if (new_hour == 0) {
        new_hour = 0;
    }

    if (new_minute >= 60) {
        new_minute -= 60;
        new_hour++;
    }
}

void final_time(int new_hour, int new_minute) {
    cout << "By the time you are done waiting it will be: ";
    cout << setw(2) << setfill('0') << new_hour << ":"
         << setw(2) << setfill('0')<< new_minute<<endl;
}
/*Write a program that requests the current time and a waiting time as two
integers for the number of hours and the number of minutes to wait. The
program then outputs what the time will be after the waiting period. Use
24-hour notation for the times. Include a loop that lets the user repeat this
calculation for additional input values until the user says she or he wants
to end the program.*/