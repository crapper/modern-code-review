#include <iostream>
#include <string>
using namespace std;

bool isWin(char game[3][3]){
    bool win = false;
    // row
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    // column
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    // diagonal
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    return win;
}

int main(){
    string i, j;
    int ii, jj;
    char game[3][3] = {' '}; // Tic-tac-toe
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    cout << "X = Player 1" << endl << "O = Player 2" << endl;
    for (int n=0; n<9; n++){
        turn = !turn;  // use the not-operator to change true to false or false to true.
        bool isNum = false;
        while (isNum == false)
        {
            if (turn == false)
                cout << "Player 1: ";
            else
                cout << "Player 2: ";
            cout << "Which cell to mark? i:[0..2], j:[0..2]: ";
            cin >> i >> j;
            try {
                ii = stoi(i);
                jj = stoi(j);
            }catch (...) {
                cout << "You did not enter a number. Try again next time." << endl;
            }
        }
        if (turn == false)
            game[ii][jj] = player1;
        else 
            game[ii][jj] = player2;
        if (isWin(game)){
            cout << "Win!" << endl;
            break; // need to terminate the problem
        }
    }
    bool isNotFull = false;
    for (int k=0; k<3; k++){
        for (int l=0; l<3; l++)
            if (game[k][l] == ' ') isNotFull = true;
    }
    if (!isNotFull)
        cout << "Tie!" << endl;

    // show the game to console
    cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
    cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
    cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
    return 0;
}