#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUMBER_OF_CHAPTERS = 17; // 18 total chapters
int chapter_number = 18;  // Starts at 18 and counts down to 1

string user, go_again, userInput;
ifstream ini_file;

void openFile(ifstream &ini_file);
void userQuestion(string &user, string &userInput);
void botAnswer(ifstream &ini_file);
void closeFile(ifstream &ini_file);
string replaceChapterPlaceholder(string answer);

int main() {
    do {
        openFile(ini_file);

        while (true) {  // **Loop until all responses are read**
            userQuestion(user, userInput);

            if (userInput == "0") { //allows user to break out of program
                break;
            }
            botAnswer(ini_file);

            if (ini_file.eof()) { // **When answers run out, restart**
                ini_file.clear();
                ini_file.seekg(0);
            }
    
        }

        closeFile(ini_file);

        cout << "Would you like to start over? (y/n): ";
        cin >> go_again;
        cin.ignore(); 

    } while (go_again == "y" || go_again == "Y");

    return 0;
}

void openFile(ifstream &ini_file) {
    ini_file.open("C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\project 6.txt");
    if (ini_file.fail()) {
        cout << "Error opening file.\n";
        exit(1);
    }
}

void userQuestion(string &user, string &userInput) {
    cout << "Enter your question. Enter 0 to exit program: ";
    getline(cin, userInput); // Read the entire input
}

void botAnswer(ifstream &ini_file) {
    string answer;

    if (getline(ini_file, answer)) {  
        answer = replaceChapterPlaceholder(answer);
        cout << "Answer: " << answer << endl;
    }
}

string replaceChapterPlaceholder(string answer) {
    size_t pos = answer.find("#N");
    if (pos != string::npos) {
        answer.replace(pos, 2, to_string(chapter_number));

        // Decrease chapter number, reset when it reaches 0
        chapter_number--;
        if (chapter_number == 0) {
            chapter_number = 18;
        }
    }
    return answer;
}

void closeFile(ifstream &ini_file) {
    ini_file.close();
}
