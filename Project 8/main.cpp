#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
 char calc;
 double input, pi_value, term;
 do {
     int i = 0;
     pi_value = 0.0;
     cout<<"Please enter a number: \n";
     cin>>input;
      for (int i = 0; i <= input; i++) {  // Use i to iterate the terms
            term = pow(-1, i) / (2 * i + 1);  // Correct calculation
            pi_value += term;
 }
     double final_value = 4 * pi_value;
     cout<<'\n'<<final_value<<endl;
     cout<<"\nWould you like to make another calculation? (y/n)"<<endl;
     cin>>calc;

 }
    while (calc == 'y' || calc == 'Y');
    return 0;
}
/*An approximate value of pi can be calculated using the series given below:
pi = 4 [ 1 – 1/3 + 1/5 – 1/7 + 1/9 ... + ((–1)n)/(2n + 1) ]
 Write a C++ program to calculate the approximate value of pi using this
series. The program takes an input n that determines the number of terms
in the approximation of the value of pi and outputs the approximation.
Include a loop that allows the user to repeat this calculation for new values
n until the user says she or he wants to end the program.*/