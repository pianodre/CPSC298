#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <tuple>

class Game{ 
    public:
        Game(); //Fills the game board
        ~Game();
        void printBoard();
        char getPos(int r, int c);
        void setPos(int r, int c, char x);
        std::tuple<int, int> getBoat();
    private:
        char board[4][5];
        const static int rows = 4;
        const static int cols = 5;

        int ship_row;
        int ship_col;

};

#endif