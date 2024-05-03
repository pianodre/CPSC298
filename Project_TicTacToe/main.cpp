#include "Game.h"

int main() {
    Game TicTacToe;

    TicTacToe.printBoard();

    while (!TicTacToe.checkWin() && !TicTacToe.checkTie()) {
        srand(time(0));
        int row, col;

        cout << "Enter a row: ";
        cin >> row;
        cout << "Enter a column: ";
        cin >> col;

        if (TicTacToe.updateSquare(row, col, 'X')) {
            TicTacToe.printBoard();
            if (!TicTacToe.checkWin()) {
                TicTacToe.computerTurn(row,col);
                TicTacToe.printBoard();
            }
        } else {
            cout << "Invalid position. Try again." << endl;
        }

    }

    if (TicTacToe.checkTie()) {
        cout << "The game is a tie!" << endl;
    } else {
        cout << "Game Over!" << endl;
    }

    return 0;
}
