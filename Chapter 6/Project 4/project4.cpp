#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>

using namespace std;

void calculate(float &average);
void count_words(double &wordCount, ifstream &infile);
void character_count(double &characterCount, ifstream &infile);
void openFile(ifstream &infile);

ifstream infile;
double wordCount = 0, characterCount = 0;
float average = 0;
string go_again;

int main() {
    do {
        openFile(infile);
        calculate(average);
        infile.close();
        cout << "Would you like to go again?" << endl;
        cin >> go_again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (go_again == "y" || go_again == "Y");
    return 0;
}

void openFile(ifstream &ini_file) {
    ini_file.open("C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\project 4.txt");
    if (ini_file.fail()) {
        cout << "Error opening file.\n";
        exit(1);
    }
}
void count_words(double &wordCount, ifstream &infile) {
    wordCount = 0;
    string line;
    while (getline (infile, line)) {
    stringstream ss(line);
    string word;

        while (ss >> word) {
        wordCount ++;
        }
    }
    infile.clear(); // Reset file stream state
    infile.seekg(0); // Move back to the beginning of the file
}

void character_count(double &characterCount, ifstream &infile) { //don't count spaces!!
    characterCount = 0;
    string line;
    while (getline (infile, line)) {
        for (char c : line)
            if (!isspace(c) && isprint(c)) {
                characterCount++;
            }
    }
    infile.clear(); // Reset file stream state
    infile.seekg(0); // Move back to the beginning of the file
}

void calculate(float &average){
    count_words(wordCount, infile);
    character_count(characterCount, infile);
    average = characterCount / wordCount;
    cout << "There are an average of " << average << " characters in each word, " << wordCount << " words total, and " << characterCount << " total" << endl; //not showing word count and not doing loop
}
