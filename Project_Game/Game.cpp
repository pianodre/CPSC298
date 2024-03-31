#include "Game.h"
using namespace std;

Game::Game() { //Fill the board and place the one ship
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '-';
        }
    }
    // Randomly add the battleship, (S)
    srand(time(NULL));
    int r = (rand()%rows); 
    int c = (rand()%cols);
    ship_row = r;
    ship_col = c;

    cout << "Ship Row: " << ship_row << "\nShip Col: " << ship_col << "\n" << endl;
}

Game::~Game() {
    // cout << "Deconstructor Run" << endl;
}

void Game::printBoard() {
    cout << "  0 1 2 3 4" << endl;
    for (int i = 0; i < rows; i++) {
        cout << i << " ";
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// TODO: Return a tuple with ship_row and ship_col
tuple<int, int> Game::getBoat() {
    tuple<int, int> s = make_tuple(ship_row, ship_col);
    return s;
}

char Game::getPos(int r, int c) { 
    return board[r][c];
}

void Game::setPos(int r, int c, char x) {
    board[r][c] = x;
}