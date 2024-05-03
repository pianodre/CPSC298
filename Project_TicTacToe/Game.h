#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
public:
    Game();
    ~Game();

    void printBoard();
    bool checkWin();
    bool updateSquare(int row, int col, char c);
    void computerTurn(int row, int col); 
    int* checkTwoInARow(char board[3][3], char symbol);
    bool checkTie();
private:
    char board[3][3];
    bool firstMove = true;
    int playerRow;
    int playerCol;
    bool gameWon = false;
};

#endif
