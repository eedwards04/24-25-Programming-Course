#include <iostream>
using namespace std;
int main()
{
    int number_of_quarters, number_of_dimes, number_of_nickles;
    cout << "Press return after entering a number.\n";
    cout << "How many quarters do you have?\n";
    cin >> number_of_quarters;
    cout << "How many dimes do you have?\n";
    cin >> number_of_dimes;
    cout << "How many nickles do you have?\n";
    cin >> number_of_nickles;
    double total_amount = number_of_quarters * 25 +
                          number_of_dimes * 10 +
                          number_of_nickles * 5;
    cout << "You have " << total_amount << " cents.\n";

    return 0;
}
