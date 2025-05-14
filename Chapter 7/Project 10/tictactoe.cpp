#include <iostream>

using namespace std;

void intArray(char game_board[3][3]);
void playerTurn(char game_board[3][3], int &numberTurn);
void printBoard(char game_board[3][3]);

int main() {
    int numberTurn = 0;
    char game_board[3][3];  

    intArray(game_board); 

    while (numberTurn < 9) {
        printBoard(game_board);
        playerTurn(game_board, numberTurn);
    }

    printBoard(game_board);
    cout << "Game over!" << endl;
    return 0;
}

void intArray(char game_board[3][3]) { 
    char values[3][3] = { 
        {'1', '2', '3'}, 
        {'4', '5', '6'}, 
        {'7', '8', '9'} 
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game_board[i][j] = values[i][j];
        }
    }
}

void playerTurn(char game_board[3][3], int &numberTurn) {
    int userPick;
    int rowIndex, colIndex;

    while (true) {
        cout << "Player " << (numberTurn % 2 == 0 ? 'X' : 'O') << ", pick a spot on the board (1-9): ";
        cin >> userPick;

        if (userPick < 1 || userPick > 9) {
            cout << "Invalid input! Choose a number between 1 and 9.\n";
            continue;
        }

        rowIndex = (userPick - 1) / 3;
        colIndex = (userPick - 1) % 3;

        if (game_board[rowIndex][colIndex] == 'X' || game_board[rowIndex][colIndex] == 'O') {
            cout << "Spot already taken! Choose another.\n";
            continue;
        }

        game_board[rowIndex][colIndex] = (numberTurn % 2 == 0) ? 'X' : 'O';
        numberTurn++;
        break;
    }
}

void printBoard(char game_board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << game_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
