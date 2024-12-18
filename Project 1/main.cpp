#include <iostream>
#include <iomanip>
using namespace std;

void getInput(int& hour_input, int& minute_input, char& am_pm);
void conversion(int hour_input, int& new_hour);
void final_time(int new_hour, int minute_input, char am_pm);

int main() {
    char go_again;

    do{
        int hour_input = 0, minute_input = 0, new_hour = 0, new_time = 0;
        char am_pm = 0;

        getInput(hour_input, minute_input, am_pm);
        conversion(hour_input, new_hour);
        final_time(new_hour, minute_input, am_pm);

        cout<<"Would you like to make another conversion (y/n)?\n";
        cin>>go_again;

    }while (go_again == 'y' || go_again == 'Y');
    return 0;
}

void getInput(int& hour_input, int& minute_input, char& am_pm) {
    cout << "Please enter a time in 24-hour notation (HH:MM): \n";
    char colon; // gets rid of ':'

    cin >> hour_input >> colon >> minute_input;

    if (hour_input < 12) {
        am_pm = 'A';
    } else {
        am_pm = 'P';
    }
}

void conversion(int hour_input, int& new_hour) {
    if (hour_input > 12)
        new_hour = hour_input - 12;
    else if (hour_input == 0) {
        new_hour = 12;
    }
    else {
        new_hour = hour_input;
    }
}

void final_time(int new_hour, int minute_input, char am_pm) {
    cout << "Your time converted to 12-hour notation is: ";
    cout << setw(2) << setfill('0') << new_hour << ":"
         << setw(2) << setfill('0') << minute_input << " "
         << (am_pm == 'A' ? "AM" : "PM") << endl;
}
/*. Write a program that converts from 24-hour notation to 12-hour notation.
For example, it should convert 14:25 to 2:25 PM. The input is given as two
integers. There should be at least three functions, one for input, one to do the
conversion, and one for output. Record the AM/PM information as a value of
type char, ‘A’ for AM and ‘P’ for PM. Thus, the function for doing the conversions will have a call-by-reference formal parameter of type char to record
whether it is AM or PM. (The function will have other parameters as well.)
Include a loop that lets the user repeat this computation for new input values
again and again until the user says he or she wants to end the program.*/