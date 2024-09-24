#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double roundToNearestHundredth(double value) {
    return round(value * 100.0) / 100.0;}

int main()
{
    int user_weight, user_height, user_age;
    double num_bars;
    char user_sex;
    cout<<"Enter your weight in pounds: \n";
    cin>>user_weight;
    cout<<"Enter your height in inches: \n";
    cin>>user_height;
    cout<<"Enter your age in years: \n";
    cin>>user_age;
    cout<<"Enter M if you are male, F if you are female: \n";
    cin>>user_sex;
    if (user_sex == 'F') {
        num_bars = 655 + (4.3 * user_weight) + (4.7 * user_height) - (4.7 * user_age);
    }
    else
        num_bars = 66 + (6.3 * user_weight) + (12.9 * user_height) - (6.8 * user_age);
    num_bars = num_bars / 230;

    num_bars = roundToNearestHundredth(num_bars);
    cout<<fixed<<setprecision(2);
    cout<<"You would need to eat "<<num_bars<<" chocolate bars a day to maintain your weight."<<endl;
    return 0;

}

