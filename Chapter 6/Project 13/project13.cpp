#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void count_words(int &wordCount, ifstream &infile);
void openFile(ifstream &infile);

ifstream infile;
int wordCount = 0;
string go_again;

int main() {
    do{
        openFile(infile);
        count_words(wordCount, infile);
        infile.close(); 
        cout << "Would you like to search another file?" << endl;
        cin >> go_again;
    } 
    while (go_again == "y" || go_again == "Y");
    return 0;
}
void openFile(ifstream &ini_file) {
    string userInput;
    cout << "What file would you like to open? " << endl;
    cin >> userInput;
    ini_file.open(userInput);
    if (ini_file.fail()) {
        cout << "Error opening file." << endl;
        exit(1);
    }
}
void count_words(int &wordCount, ifstream &infile) {
    wordCount = 0;
    string line;
    while (getline (infile, line)) {
    stringstream ss(line);
    string word;
        while (ss >> word) {
        wordCount ++;
        }
    }
    cout << "There are a total of " << wordCount << " words" << endl;
}

