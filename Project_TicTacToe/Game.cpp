#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '~';
        }
    }
}

Game::~Game() {}

void Game::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Game::checkWin() {
    for (int i = 0; i < 3; i++) { // Check Horizontal
        if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && (board[i][0] != '~')) {
            if (board[i][0] == 'X') {
                if (!gameWon) {
                    cout << "You win!" << endl;
                }
            } else {
                cout << "The computer won." << endl;
            }
            gameWon = true; // Set gameWon to true if the game is won
            return true;
        }
    }
    for (int j = 0; j < 3; j++) { // Check Vertical
        if ((board[0][j] == board[1][j]) && (board[0][j] == board[2][j]) && (board[0][j] != '~')) {
            if (board[0][j] == 'X') {
                if (!gameWon) {
                    cout << "You win!" << endl;
                }
            } else {
                cout << "The computer won." << endl;
            }
            gameWon = true; // Set gameWon to true if the game is won
            return true;
        }
    }
    // check top left diagonal
    if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) && (board[0][0] != '~')) {
        if (board[0][0] == 'X') {
            if (!gameWon) {
                    cout << "You win!" << endl;
                }
        } else {
            cout << "The computer won." << endl;
        }
        gameWon = true; // Set gameWon to true if the game is won
        return true;
    }
    // check top right diagonal
    if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[0][2] != '~')) {
        if (board[0][2] == 'X') {
            cout << "You win!" << endl;
        } else {
            cout << "The computer won." << endl;
        }
        gameWon = true; // Set gameWon to true if the game is won
        return true;
    }
    // If the game is not won, return false
    return false;
}

bool Game::updateSquare(int row, int col, char c) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '~') {
        board[row][col] = c;
        return true;
    }
    return false;
}

int* Game::checkTwoInARow(char board[3][3], char symbol) {
    static int result[2] = {-1, -1}; // Initialize with invalid indices

    // Check rows
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == '~') ||
            (board[i][0] == symbol && board[i][2] == symbol && board[i][1] == '~') ||
            (board[i][1] == symbol && board[i][2] == symbol && board[i][0] == '~')) {
            for (int k = 0; k < 3; ++k) {
                if (board[i][k] == '~') {
                    result[0] = i;
                    result[1] = k;
                    return result;
                }
            }
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if ((board[0][j] == symbol && board[1][j] == symbol && board[2][j] == '~') ||
            (board[0][j] == symbol && board[2][j] == symbol && board[1][j] == '~') ||
            (board[1][j] == symbol && board[2][j] == symbol && board[0][j] == '~')) {
            for (int k = 0; k < 3; ++k) {
                if (board[k][j] == '~') {
                    result[0] = k;
                    result[1] = j;
                    return result;
                }
            }
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == '~') ||
        (board[0][0] == symbol && board[2][2] == symbol && board[1][1] == '~') ||
        (board[1][1] == symbol && board[2][2] == symbol && board[0][0] == '~')) {
        for (int k = 0; k < 3; ++k) {
            if (board[k][k] == '~') {
                result[0] = k;
                result[1] = k;
                return result;
            }
        }
    }

    if ((board[0][2] == symbol && board[1][1] == symbol && board[2][0] == '~') ||
        (board[0][2] == symbol && board[2][0] == symbol && board[1][1] == '~') ||
        (board[1][1] == symbol && board[2][0] == symbol && board[0][2] == '~')) {
        int k = 0;
        for (int l = 2; l >= 0; --l) {
            if (board[k][l] == '~') {
                result[0] = k;
                result[1] = l;
                return result;
            }
            k++;
        }
    }

    // No two-in-a-row found
    result[0] = -1;
    result[1] = -1;
    return result;
}

void Game::computerTurn(int row, int col) {
    playerRow = row;
    playerCol = col;

    // First move logic
    if (firstMove) {
        if (board[1][1] == '~') { // If the middle is open, take it
            updateSquare(1, 1, 'O');
            firstMove = false; // Set firstMove to false after the first move
            return;
        }
    }

    // Check if O can win in the next move and complete the row, column, or diagonal
    int* result = checkTwoInARow(board, 'O');
    if (result[0] != -1 && result[1] != -1) {
        if (board[result[0]][result[1]] == '~') {
            cout << "Found winning move for O at (" << result[0] << ", " << result[1] << ")" << endl;
            updateSquare(result[0], result[1], 'O');
            return;
        }
    }

    // Check if X can win in the next move and block it
    result = checkTwoInARow(board, 'X');
    if (result[0] != -1 && result[1] != -1) {
        if (board[result[0]][result[1]] == '~') {
            cout << "Found blocking move for O at (" << result[0] << ", " << result[1] << ")" << endl;
            updateSquare(result[0], result[1], 'O');
            return;
        }
    }

    // Try to make two in a row
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '~') { // Check if cell is empty
                // Simulate placing 'O' and see if it results in a win
                board[i][j] = 'O';
                
                // Simulate human player's move (placing 'X' in an empty cell)
                int* humanResult = checkTwoInARow(board, 'X');
                if (humanResult[0] != -1 && humanResult[1] != -1) {
                    // If human player has a winning move, undo the simulation and continue
                    board[i][j] = '~';
                    continue;
                }
                
                // Check if 'O' can win after the human player's move
                if (checkWin()) {
                    cout << "Found immediate win for O at (" << i << ", " << j << ")" << endl;
                    updateSquare(i, j, 'O');
                    return;
                }
                
                // Undo the simulation
                board[i][j] = '~';
            }
        }
    }

    // Check if corners are available to play
    if (board[0][0] == '~') { // Top-left corner
        updateSquare(0, 0, 'O');
        return;
    }
    if (board[0][2] == '~') { // Top-right corner
        updateSquare(0, 2, 'O');
        return;
    }
    if (board[2][0] == '~') { // Bottom-left corner
        updateSquare(2, 0, 'O');
        return;
    }
    if (board[2][2] == '~') { // Bottom-right corner
        updateSquare(2, 2, 'O');
        return;
    }
}

bool Game::checkTie() {
    // Check if all squares are filled and no player has won
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '~') { // If any square is empty, game is not tied
                return false;
            }
        }
    }
    // If all squares are filled and no player has won, game is tied
    return !checkWin();
}