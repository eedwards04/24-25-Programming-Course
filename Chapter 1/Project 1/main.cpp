#include <iostream>

#include <iostream>
 using namespace std;
int main( )
{
    int number_one, number_two;
    cout << "Press return after entering a number.\n";
    cout << "Enter your first number:\n";
    cin >> number_one;
    cout << "Enter another number:\n";
    cin >> number_two;
    int const product_answer = number_one * number_two;
    int const sum_answer = number_one + number_two;
    cout << "The product of "<<number_one<<" and "<<number_two<<" is "<<product_answer<<"\n";
    cout << "The sum is " <<sum_answer<< endl;
    return 0;
}
