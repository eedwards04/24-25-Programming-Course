#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN_LENGTH = 5;
string go_again;

// Function to generate random mapping of digits 0-9 to numbers 1-3
void generateRandomMapping(int mapping[]) {
    for (int i = 0; i < 10; ++i) {
        mapping[i] = rand() % 3 + 1;  // random number between 1 and 3
    }
}

// Function to get the expected response based on the user's actual PIN
void getExpectedResponse(const int actualPIN[], const int mapping[], int expected[]) {
    for (int i = 0; i < PIN_LENGTH; ++i) {
        expected[i] = mapping[actualPIN[i]];
    }
}

// Function to compare user's input with expected response
bool isCorrect(int userInput[], int expected[]) {
    for (int i = 0; i < PIN_LENGTH; ++i) {
        if (userInput[i] != expected[i]) return false;
    }
    return true;
}

int main() {
    do {
    srand(time(0));  // seed for random number generation

    // Step 1: Actual PIN stored internally
    int actualPIN[PIN_LENGTH] = {1, 2, 3, 4, 5};

    // Step 2: Generate random mapping for digits 0 to 9
    int mapping[10];
    generateRandomMapping(mapping);

    // Step 3: Display challenge (NUM mapping)
    cout << "PIN: ";
    for (int i = 0; i < 10; ++i) {
        cout << i << " ";
    }
    cout << endl;

    cout << "NUM: ";
    for (int i = 0; i < 10; ++i) {
        cout << mapping[i] << " ";
    }
    cout << endl;

    // Step 4: Ask user for their response
    cout << "Enter the corresponding NUM values for your PIN: ";
    int userInput[PIN_LENGTH];
    for (int i = 0; i < PIN_LENGTH; ++i) {
        cin >> userInput[i];
    }

    // Step 5: Get expected transformed PIN
    int expectedResponse[PIN_LENGTH];
    getExpectedResponse(actualPIN, mapping, expectedResponse);

    // Step 6: Check response
    if (isCorrect(userInput, expectedResponse)) {
        cout << "Access Granted" << endl;
    } else {
        cout << "Access Denied" << endl;
    }

    cout << "Would you like to go again?\n";
    cin >> go_again;
    } while (go_again == "y" || go_again == "Y");

    return 0;
}
