#include <iostream>
#include <cmath>
#include <complex>// For complex numbers
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c;
    char continue_calc;
    cout << "A quadratic equation looks like ax^2 + bx + c = 0 where a, b, and c can be any integer.";
    do {
        cout << "\nWhat is your value for a?\n";
        cin >> a;
        cout << "What is your value for b?\n";
        cin >> b;
        cout << "What is your value for c?\n";
        cin >> c;

        double discriminant = (b * b) - (4 * a * c);

        if (discriminant > 0) {
            double first_calc = (-b + sqrt(discriminant)) / (2 * a);
            cout<<fixed<<setprecision(2);
            double sec_calc = (-b - sqrt(discriminant)) / (2 * a);
            cout<<fixed<<setprecision(2);
            cout << "The solutions are: " << first_calc << " and " << sec_calc << endl;
        }
        else if (discriminant == 0) {
            double calc = (-b + sqrt(discriminant)) / (2 * a);
            cout<<fixed<<setprecision(2);
            cout << "The solutions are: " << calc << endl;
        }
        else {
            complex<double> first_calc = (-b + sqrt(complex<double>(discriminant, 0))) / (2.0 * a);
            cout<<fixed<<setprecision(2);
            complex<double> sec_calc = (-b - sqrt(complex<double>(discriminant, 0))) / (2.0 * a);
            cout << "The solutions are: ";
            cout << real(first_calc) << (imag(first_calc) >= 0 ? " + " : " - ") << abs(imag(first_calc)) << "i and ";
            cout << real(sec_calc) << (imag(sec_calc) >= 0 ? " + " : " - ") << abs(imag(sec_calc)) << "i" << endl;        }

        cout << "Would you like to make another calculation? (y / n)\n";
        cin >> continue_calc;

    } while (continue_calc == 'y' || continue_calc == 'Y');

    return 0;
}

//Write a C++ program that solves a quadratic equation to find its roots. The roots of a quadratic equation
//ax2 + bx + c = 0 (where a is not zero) are given by the formula (–b ± sqrt(b2 – 4ac)) / 2a
 //The value of the discriminant (b2 – 4ac) determines the nature of roots.
//If the value of the discriminant is zero, then the equation has a single real
//root. If the value of the discriminant is positive then the equation has two
//real roots. If the value of the discriminant is negative, then the equation
//has two complex roots.
// The program takes values of a, b, and c as input and outputs the roots. Be
//creative in how you output complex roots. Include a loop that allows the
//user to repeat this calculation for new input values until the user says she
//or he wants to end the program.