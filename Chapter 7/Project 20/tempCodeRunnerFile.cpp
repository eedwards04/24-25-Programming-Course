#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_AGE = 120; // from age 0 to 119

int main() {
    double maleProb[MAX_AGE] = {0};
    double femaleProb[MAX_AGE] = {0};
    int age;
    string sex, go_again;

    srand(time(0)); // Seed the random number generator

    do {
        // Step 1: Read probabilities from file
        ifstream inFile("C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\chapter7.txt");
        if (!inFile) {
            cerr << "Error opening file.\n";
            return 1;
        }

        int fileAge;
        for (int i = 0; i < MAX_AGE; ++i) {
            if (!(inFile >> fileAge >> maleProb[i] >> femaleProb[i])) {
                cerr << "Error reading data for age " << i << endl;
                return 1;
            }
        }
        inFile.close();

        // Validate probabilities
        for (int i = 0; i < MAX_AGE; ++i) {
            if (maleProb[i] < 0 || maleProb[i] > 1 || femaleProb[i] < 0 || femaleProb[i] > 1) {
                cerr << "Invalid probability at age " << i << ": Male Prob = " << maleProb[i]
                     << ", Female Prob = " << femaleProb[i] << endl;
                return 1;
            }
        }

    
        cout << "Enter your sex (m/f): ";
        cin >> sex;

        cout << "Enter your current age (0-120): ";
        cin >> age;

        // Basic validation
        if ((sex != "m" && sex != "f") || age < 0 || age >= MAX_AGE) {
            cout << "Invalid input.\n";
            return 1;
        }

        // Begin simulation
        while (age < MAX_AGE) {
            double prob = (sex == "m") ? maleProb[age] : femaleProb[age];
            double randNum = static_cast<double>(rand()) / RAND_MAX;

            if (randNum <= prob) {
                break; // User dies at current age
            }
            age++;
            prob = prob * 100;
            int newNum = randNum * 100;
            cout << " random number is " << randNum << " or also " << newNum << "% the probability is " << prob <<"%" << endl;
        }
        
        cout << "Based on simulation, you are predicted to live to age " << age << "." << endl;
        cout << "Would you like to go again? (y/n): ";
        cin >> go_again;

    } while (go_again == "y" || go_again == "Y");

    return 0;
}