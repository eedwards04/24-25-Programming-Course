#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

double metabolic_rate(double P_par);
double physical_active(int intensity_par, double P_par, double minutes_par);

double user_P, user_minutes;
int user_intensity, user_fav_food;
int main() {
    char go_again;
    do {
        cout << "Enter a weight in pounds: \n";
        cin >> user_P;
        cout << "Enter the intensity of the activity completed: \n";
        cin >> user_intensity;
        cout << "Enter the number of minutes spent exercising: \n";
        cin >> user_minutes;
        cout << "How many calories are in one serving of your favorite food? \n";
        cin >> user_fav_food;

        double metabolic_calories = metabolic_rate(user_P);
        double physical_calories = physical_active(user_intensity, user_P, user_minutes);

        double calories_needed = metabolic_calories + physical_calories;

        double calories_digested = user_fav_food * .1;
        double total_calories = calories_digested + calories_needed;

        // 205 8 45 1000 = 5 servings

        double food_servings = total_calories / user_fav_food;

        cout << fixed << setprecision(2);
        cout << "You need to eat approximately " << food_servings << " servings of your favorite food per day to maintain your weight." << endl;
        cout << "Would you like to make another conversion (y/n)?\n";
        cin >> go_again;
    } while (go_again == 'y' || go_again == 'Y');
    return 0;
}

// Calculate metabolic rate
double metabolic_rate(double P_par) {
    double metabolic_calc = 70 * pow((P_par / 2.2),0.756);
    return metabolic_calc;
}

// Calculate physical activity calories
double physical_active(int intensity_par, double P_par, double minutes_par) {
    double physical_calc = 0.0385 * intensity_par * P_par * minutes_par;
    return physical_calc;
}

/* Use these functions in a program that inputs a person’s weight, an estimate
for the intensity of physical activity, the number of minutes spent performing the physical activity, and the number of calories in one serving of your
favorite food. The program should then calculate and output how many
servings of that food should be eaten per day to maintain the person’s current weight at the specified activity level. The computation should include
the energy that is required to digest food.
You can find estimates of the caloric content of many foods on the Web.
For example, a double cheeseburger has approximately 1000 calories.*/
