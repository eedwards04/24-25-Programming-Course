#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>

using namespace std;

string getUserInput();
void processPayment(string paid, double &amount_left);
void displayAmountLeft(double amount_left);
void displaySuccessMessage(double amount_left);

int main() {
    char go_again;
    double amount_left; // Total cost of a twinkie
    string paid;
    do {
        amount_left = 3.50; // Total cost of a twinkie
        do {
            cout << "It costs $3.50 to buy a deep-fried twinkie.\n";
            paid = getUserInput();
            processPayment(paid, amount_left);

            if (amount_left > 0) {
                displayAmountLeft(amount_left);
            } else {
                displaySuccessMessage(amount_left);
            }
        } while (amount_left > 0);
        cout<< "Would you like to go again?\n";
        cin >> go_again;
    } while (go_again == 'y' || go_again == 'Y');
    return 0;
}



string getUserInput() {
    string paid;
    cout << "Enter a coin (n, d, q, dollar):\n";
    cin >> paid;
    for (auto &c : paid) c = tolower(c); // Convert to lowercase to handle variations
    return paid;
}

void processPayment(string paid, double &amount_left) {
    if (paid == "n") {
        amount_left -= 0.05;
    } else if (paid == "d") {
        amount_left -= 0.10;
    } else if (paid == "q") {
        amount_left -= 0.25;
    } else if (paid == "dollar") {
        amount_left -= 1.00;
    } else {
        cout << "Invalid input. Please try again.\n";
    }
}

void displayAmountLeft(double amount_left) {
    cout << fixed << setprecision(2);
    cout << "Amount left to pay: $" << amount_left << "\n";
}

void displaySuccessMessage(double amount_left) {
    if (amount_left == 0) {
        cout << "Enjoy your deep-fried twinkie!\n";
    } else {
        double change = -amount_left; // To convert negative change to positive
        cout << fixed << setprecision(2);
        cout << "Enjoy your deep-fried twinkie! You have $" << change << " in change.\n";
    }
}


/*You have invented a vending machine capable of deep frying twinkies.
Write a program to simulate the vending machine. It costs $3.50 to buy a
deep-fried twinkie, and the machine only takes coins in denominations of
a dollar, quarter, dime, or nickel. Write code to simulate a person putting
money into the vending machine by repeatedly prompting the user for the
next coin to be inserted. Output the total entered so far when each coin is
inserted. When $3.50 or more is added, the program should output “Enjoy
your deep-fried tinkie” along with any change that should be returned. */