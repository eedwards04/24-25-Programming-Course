#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double price, inflation_rate, num_years;
    cout<<"What does the item cost now?\n";
    cin>>price;
    cout<<"What is the rate of inflation? Give the rate in a percent format\n";
    cin>>inflation_rate;
    cout<<"How many years would you like to input?\n";
    cin>>num_years;
    inflation_rate=inflation_rate/100;
    for (int i = 0; i < num_years; i++){
        price = price * (1+inflation_rate);
        cout<<fixed<<setprecision(2);

    }
    cout<<"After "<<num_years<<" year the price will be $"<<price<<endl;
    return 0;
}

