#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double calculate_average(int quiz_scores[], int num_scores) { //function that calculates the average score
    double sum = 0;
    for (int i = 0; i < num_scores; i++) {
        sum += quiz_scores[i];
    }
    return sum / num_scores;
}

void process_student(ifstream &in_file, ofstream &out_file) { //processes data for each student
    string last_name, first_name;
    int quiz_scores[10];

    in_file >> last_name >> first_name; //reads students data
    for (int i = 0; i < 10; i++) {
        in_file >> quiz_scores[i];
    }

    double average = calculate_average(quiz_scores, 10); //calls function that calculates average

    // Write the data to the output file with the average at the end
    out_file << last_name << " " << first_name;
    for (int i = 0; i < 10; i++) {
        out_file << " " << quiz_scores[i];
    }
    out_file << " " << fixed << setprecision(2) << average << endl; // Format the average to 2 decimal places
}

int main() {
    string input_file_name, output_file_name, go_again;
    do {
    // Open the input and output files
    ifstream in_file("C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\project 2.txt");
    ofstream out_file("C:\\Users\\ellae\\OneDrive\\Desktop\\C++\\Chapter 6 text files\\project 2 new.txt");

    if (!in_file) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
    if (!out_file) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // Process each student in the input file
    while (!in_file.eof()) {
        process_student(in_file, out_file);
    }

    // Close the files
    in_file.close();
    out_file.close();

    cout << "Done! The results have been written to the output file." << endl;
    cout << "Would you like to search another file?" << endl;
    cin >> go_again;
    } while (go_again == "y" || go_again == "Y");
    return 0;
}