#include <iostream>
#include <iomanip>
using namespace std;

double hat_calc(double weight, double height);
double jacket_calc(double weight, double height, int age);
double waist_calc(double weight, int age);

double user_weight, user_height;
int user_age;
int main() {
    char go_again;
    do {
        cout<<"Enter a weight in pounds: \n";
        cin>>user_weight;
        cout<<"Enter a height in inches: \n";
        cin>>user_height;
        cout<<"Enter an age: \n";
        cin>>user_age;
        double hat_size = hat_calc(user_weight, user_height);
        double jacket_size = jacket_calc(user_weight, user_height, user_age);
        double waist_size = waist_calc(user_weight, user_age);

        cout << fixed << setprecision(2);
        cout << "Hat size: " << hat_size << endl;
        cout << fixed << setprecision(2);
        cout << "Jacket size (chest in inches): " << jacket_size << endl;
        cout << fixed << setprecision(2);
        cout << "Waist in inches: " << waist_size << endl;
        cout << "Would you like to make another conversion (y/n)?\n";
        cin >> go_again;

} while (go_again == 'y' || go_again == 'Y');
    return 0;
}

double hat_calc(double weight, double height) {
    return (weight / height) * 2.9;
}

double jacket_calc(double weight, double height, int age) {
    int age_calc;
    double size = (height * weight ) / 288;
    if (age > 39) {
        int age_calc = (age - 30) / 10;
        size += age_calc * 0.125;
    }
    return size;
}

double waist_calc(double weight, int age) {
    double size = weight / 5.7;
    if (age > 28) {
        int age_calc = (age - 28) / 2;
        size += age_calc * .1;
    }
    return size;
}
