#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in_stream;
ofstream out_stream;
string content, string2, string1 = "#N#", go_again;

int main() {
    do {

    cout << "Please enter the new name: \n";
    cin >> string2;
    ifstream ini_file {"C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\project 1.txt"};//og file
    if (ini_file.fail()) {
        cout << "Error opening file.\n";
    }
    ofstream out_file {"C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\project 1 new.txt"}; //new file
    if (out_file.fail()) {
        cout << "Error opening new file.\n";
    }
    getline(ini_file, content, '\0');  // '\0' reads the entire file


    size_t pos = content.find(string1); // Replace #N# with the entered name
    if (pos != string::npos) {
        content.replace(pos, string1.length(), string2);
    }

    out_file << content; //add content to new file

    ini_file.close(); // close files
    out_file.close();
    cout << "Would you like to search another file?" << endl;
    cin >> go_again;
    } while (go_again == "y" || go_again == "Y");
   return 0;
}
