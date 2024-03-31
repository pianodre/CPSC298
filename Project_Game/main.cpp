#include "Game.h"
using namespace std;

int main() {
    Game battleship; //Creates the game board
    battleship.printBoard(); //Prints the board

    while (true) {
        int guess_row; int guess_col;

        cout << "Enter a row: " << endl; cin >> guess_row;
        cout << "Enter a col: " << endl; cin >> guess_col;

        tuple<int,int> g = make_tuple(guess_row, guess_col);
        // TODO: Compare the guess row and col with the ship row and col using getPos
        if (g == battleship.getBoat()) { 
            cout << "\nYou found the Ship @ " << guess_row << ", " << guess_col << endl;
            battleship.setPos(guess_row, guess_col, 'S');
            battleship.printBoard();
            return 0;
        } else {
            cout << "\nMiss: Guess again!" << endl;
            battleship.setPos(guess_row, guess_col, 'x');
            battleship.printBoard();
        }

    }


    return 0;
}