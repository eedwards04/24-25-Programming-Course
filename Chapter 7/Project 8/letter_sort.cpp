#include <iostream>
#include <cstring>
using namespace std;

// Function to sort letters by their count (Descending order)
void sortByFrequency(char letters[], int counts[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (counts[j] > counts[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap counts
        int tempCount = counts[i];
        counts[i] = counts[maxIndex];
        counts[maxIndex] = tempCount;

        // Swap letters to keep alignment
        char tempChar = letters[i];
        letters[i] = letters[maxIndex];
        letters[maxIndex] = tempChar;
    }
}

int main() {
    const int ALPHABET_SIZE = 26;
    char* letters = new char[ALPHABET_SIZE];
    int* counts = new int[ALPHABET_SIZE]();
    string go_again;
    
    do {
        // Initialize letters array with 'a' to 'z'
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            letters[i] = 'a' + i;
        }

        cout << "Enter a line of lowercase text ending with a period:\n";
        char ch;
        while (cin.get(ch) && ch != '.') {
            if (ch >= 'a' && ch <= 'z') {
                counts[ch - 'a']++;
            }
        }

        // Sort letters and counts arrays by frequency
        sortByFrequency(letters, counts, ALPHABET_SIZE);

        // Display results
        cout << "\nLetter   Number of Occurrences\n";
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (counts[i] > 0) {
                cout << letters[i] << "        " << counts[i] << endl;
            }
        }
        memset(counts, 0, ALPHABET_SIZE * sizeof(int));

        cout << "Would you like to go again\n";
        cin >> go_again;
        cin.ignore();
        delete[] letters;
        delete[] counts;

    } while (go_again == "y" || go_again =="Y");
    return 0;
}

