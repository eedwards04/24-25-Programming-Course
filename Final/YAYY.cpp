#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

bool initialChoice();
void addToDo();
void removeToDo();
void displayList();
void loadTodosFromFile(vector<string>& todos, vector<string>& prioritiesArray, vector<bool>& completedArray);
void saveTodosToFile(const vector<string>& todos, const vector<string>& prioritiesArray, const vector<bool>& completedArray);
void generateCompletedSVG(const vector<string>& todos, const vector<bool>& completedArray);

int main() { //welcome message and runs the program
    cout << "Hello! Welcome to the To-Do list!\n"; 
    while (initialChoice()) {
    }
    cout << "Thanks for using the To-Do list!\n";
    return 0;
}

bool initialChoice() { //what user would like to do
    string userChoice;
    cout << "\nWhat would you like to do?\n";
    cout << "Click 1 to add a To Do \n";
    cout << "Click 2 to remove a To Do \n";
    cout << "Click 3 to display current To Do's\n";
    cout << "Click 4 to end\n";
    cin >> userChoice;

    if (userChoice == "1") { //calls function based on users choice
        addToDo();
    } else if (userChoice == "2") {
        removeToDo();
    } else if (userChoice == "3") {
        displayList();
    } else if (userChoice == "4") { 
        return false;
    } else {
        cout << "Error, invalid input. Please enter a valid input\n"; //if number != an option
    }
    return true;
}

void loadTodosFromFile(vector<string>& todos, vector<string>& prioritiesArray, vector<bool>& completedArray) { //load to do from the file
    fstream file("Final Text Doc.txt", ios::in);
    if (!file) {
        return; //if file does not exists return
    }

    todos.clear(); //clears existing lists before loading new one
    prioritiesArray.clear();
    completedArray.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss(line); //read lines
        string segment; //each titl, date, priority seperated into parts
        vector<string> parts; 

        while (getline(ss, segment, '|')) { //splits file line using |
            parts.push_back(segment);
        }

        if (parts.size() >= 4) { //makes sure data structure is valid
            string task = parts[0] + "|" + parts[1] + "|" + parts[2] + "|" + parts[3];
            todos.push_back(task);
            prioritiesArray.push_back(parts[3]); //gets priority from data
        }

        bool isCompleted = (parts.size() > 4 && parts[4] == "C"); //is the array completed
        completedArray.push_back(isCompleted);
    }

    file.close(); //close the file
}

void saveTodosToFile(const vector<string>& todos, const vector<string>& prioritiesArray, const vector<bool>& completedArray) {
    fstream file("Final Text Doc.txt", ios::out | ios::trunc); //saves updated to do list to file
    for (size_t i = 0; i < todos.size(); i++) {
        string taskLine = todos[i];
        file << taskLine << "\n";
    }
    file.close();
}

void addToDo() {
    string name, priority, date;
    int num = 0;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //prevents newline issues

    vector<string> todos, prioritiesArray;
    vector<bool> completedArray;
    loadTodosFromFile(todos, prioritiesArray, completedArray);

    for (const string& line : todos) { //determines next id number
        size_t delimiterPos = line.find('|');
        if (delimiterPos != string::npos) {
            string numStr = line.substr(0, delimiterPos);
            try {
                int currentNum = stoi(numStr);
                if(currentNum > num) {
                    num = currentNum;
                }
            } catch (invalid_argument&) {
                continue;
            }
        }
    }
    num++;

    cout << "What is the title of the To Do? "; //collects user data
    getline(cin, name);
    cout << "What is the priority? (Low/Medium/High) ";
    getline(cin, priority);
    cout << "What day is it due (mm-dd-yyyy)? ";
    getline(cin, date);

    string newContent = to_string(num) + "|" + name + "|" + date + "|" + priority; //formats new to do

    fstream file("Final Text Doc.txt", ios::app); //adds to do to file
    if (!file) {
        cout << "Error opening file to add To Do.\n";
        return;
    }
    file << newContent << "| \n";
    file.close();

    cout << "To Do added!\n";
}

void removeToDo() {
    vector<string> todos, prioritiesArray;
    vector<bool> completedArray;
    loadTodosFromFile(todos, prioritiesArray, completedArray);

    if (todos.empty()) {
        cout << "There are no To Do items to remove.\n";
        return;
    }

    displayList(); //shows current to do list

    int index;
    cout << "\nEnter the number of the To Do item to remove: ";
    cin >> index;

    if (index < 1 || index > (int)todos.size()) {
        cout << "Invalid index.\n";
        return;
    }

    string userConfirmation; //confirms choice
    cout << "Are you sure you want to remove this To Do? (y/n): ";
    cin >> userConfirmation;
    if (userConfirmation == "y" || userConfirmation == "Y") {
        todos.erase(todos.begin() + index - 1);
        prioritiesArray.erase(prioritiesArray.begin() + index - 1);
        completedArray.erase(completedArray.begin() + index - 1);

        saveTodosToFile(todos, prioritiesArray, completedArray);

        cout << "To Do removed!\n";
    } else {
        cout << "To Do removal canceled.\n";
    }

    generateCompletedSVG(todos, completedArray); //edits the svg file
}

void displayList() {
    vector<string> todos, prioritiesArray;
    vector<bool> completedArray;
    loadTodosFromFile(todos, prioritiesArray, completedArray);

    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < todos.size(); i++) { //displays each thing from to do list
        stringstream ss(todos[i]);
        string id, title, date, priority;
        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, date, '|');
        getline(ss, priority, '|');

        cout << i + 1 << " | Title: " << title << " | Due: " << date
             << " | Priority: " << priority << "\n";
    }
    cout << "-------------------\n";
}

void generateCompletedSVG(const vector<string>& todos, const vector<bool>& completedArray) {
    ofstream svgFile("completed_todos.svg");
    if (!svgFile) {
        cout << "Error creating SVG file.\n";
        return;
    }
    //adds information to the svg file
    svgFile << R"(<?xml version="1.0" standalone="no"?>)"
            << "\n<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"600\" height=\"500\" font-family=\"Arial\" font-size=\"16\">\n";

    int y = 40;

    string message;
    cout << "What would you like to say to yourself? "; //message in the svg file 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, message);

    svgFile << "  <text x=\"40\" y=\"" << y << "\" fill=\"black\">Congrats! " 
            << message << "</text>\n";
    svgFile << "  <path d=\"M20 6L9 17L4 12\" stroke=\"green\" stroke-width=\"2\" fill=\"none\" "
            << "transform=\"translate(10," << y - 10 << ") scale(1.5)\"/>\n";
    y += 40;
    svgFile << "</svg>\n";
    svgFile.close();
    cout << "Completed tasks saved to SVG: completed_todos.svg\n";
}
