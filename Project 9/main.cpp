#include <iostream>
using namespace std;

int main() {
    double num_input, pos_total = 0, neg_total = 0;
    for (int counter = 1; counter <= 10; counter++){
    cout<<"Enter a number: \n";
    cin>>num_input;
        if(num_input >=0) {
            pos_total = pos_total + num_input;
        }
        else
            neg_total = neg_total + num_input;
}
    double const total = pos_total + neg_total;
    cout<<"All of the positive numbers added together equals "<<pos_total
        <<".\nAll the negative numbers added together equals "<<neg_total
        <<".\nAll of the numbers added together equals "<<total<<"."<<endl;
    return 0;
}

