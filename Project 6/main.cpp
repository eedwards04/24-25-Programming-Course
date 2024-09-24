#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double roundToNearestHundredth(double value) {
    return round(value * 100.0) / 100.0;
}
int main()
{
    int hours, num_dependents;
    double total_pay;

    cout<<"How many hours did you work this week?\n";
    cin>>hours;
    cout<<"How many dependents do you have?\n";
    cin>>num_dependents;

    if (hours <=40)
        total_pay = 16.78 * hours;
    else
        total_pay = ((hours - 40) * 25.17) + (671.2);

    double social_security = total_pay * .06;
    double fed_tax = total_pay * .14;
    double state_tax = total_pay * .05;
    double union_due = 10;
    double health_insurance = 35;

    social_security = roundToNearestHundredth(social_security);
    fed_tax = roundToNearestHundredth(fed_tax);
    state_tax = roundToNearestHundredth(state_tax);
    union_due = roundToNearestHundredth(union_due);
    health_insurance = roundToNearestHundredth(health_insurance);

    if (num_dependents >= 3)
        total_pay = total_pay - social_security - fed_tax - state_tax - union_due - health_insurance;
    else
        total_pay = total_pay - social_security - fed_tax - state_tax - union_due;

    total_pay = roundToNearestHundredth(total_pay);
    cout<<fixed<<setprecision(2);

    cout<<"Social security takes away "<<social_security<<" dollars\n";
    cout<<"Federal Income tax takes away "<<fed_tax<<" dollars\n";
    cout<<"State Income tax takes away "<<state_tax<<" dollars\n";
    cout<<"Your Union dues takes away 10 dollars";
    if (num_dependents >= 3)
        cout<<"\nYour health insurance takes away 30 dollars\n";
    else
        cout<<"\n";

    cout<<"Your take home pay is "<<total_pay<<" dollars"<<endl;
    return 0;
}
