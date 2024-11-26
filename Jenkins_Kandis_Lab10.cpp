/*
Name: Kandis Jenkins
Lab #10
Date: 11/21/2024
Description: 3D Tic Tac Toe game in C++. You can play against the computer, and the game will randomly decide who goes first and tell who the winner is. 
File name: Jenkins_Kandis_lab10.cpp
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
class TicTacToe {
    public:
        void resetBoard(); // Function to reset the board
        void displayBoard(); // Function to display the board
        int validateMove(int, int); // Function to validate a move
        void decideFirstPlayer(); // Function to decide who goes first randomly
        void switchPlayer(); // Function to switch the active player
        void checkForWinner(); // Function to check if someone has won
        void announceWinner(); // Function to announce the winner
        int currentPlayer; // Track whose turn it is, 0 = player, 1 = computer
        int gameOver = 0; // Is the game still ongoing
        char activePlayer = 'X'; // Current active player, 'X' or 'O'
    private:
        char board[3][3]; // 3x3 array for the game board
};

void TicTacToe::resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' '; // Initialize all spots to empty
        }
    }
}

void TicTacToe::displayBoard() {
    cout << endl;
    cout << "   1   2   3" << endl; // Column numbers
    for (int i = 0; i < 3; i++) {
        cout << i+1 << " "; // Row numbers
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |"; // Column separator
        }
        cout << endl;
        if (i < 2) cout << "  ---|---|---" << endl; // Row separator
    }
    cout << endl;
}

int TicTacToe::validateMove(int col, int row) {
    if (board[row-1][col-1] != ' ') {
        return 0; // Spot is taken
    } else {
        board[row-1][col-1] = activePlayer; // Mark the spot with the active player's symbol
        return 1; // Spot is available
    }
}

void TicTacToe::decideFirstPlayer() {
    srand(time(0));
    currentPlayer = rand() % 2; // Randomly decide who goes first
    if (currentPlayer == 0) {
        cout << "Player goes first" << endl << "You are X" << endl;
    } else {
        cout << "Computer goes first" << endl << "You are O" << endl;
    }
}

void TicTacToe::switchPlayer() { // Function to switch the active player
    if (activePlayer == 'X') { // If the active player is 'X'
        activePlayer = 'O'; // Change to 'O'
    } else if (activePlayer == 'O') { // If the active player is 'O'
        activePlayer = 'X'; // Change to 'X'
    }
}

void TicTacToe::checkForWinner() {
    // Check for a winner
    for (int i = 0; i < 3; i++) { // Check rows
        if ((board[i][0] == 'X' || board[i][0] == 'O') && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            announceWinner();
            return;
        }
    }
    for (int i = 0; i < 3; i++) { // Check columns
        if ((board[0][i] == 'X' || board[0][i] == 'O') && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            announceWinner();
            return;
        }
    }
    if ((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][1] && board[1][1] == board[2][2]) { // Check diagonal 1
        announceWinner();
        return;
    }
    if ((board[2][0] == 'X' || board[2][0] == 'O') && board[2][0] == board[1][1] && board[1][1] == board[0][2]) { // Check diagonal 2
        announceWinner();
        return;
    }
}

void TicTacToe::announceWinner() {
    if (currentPlayer == 0) { // If the player is winning
        cout << "Player wins!" << endl;
        gameOver = 1; // End the game
    } else if (currentPlayer == 1) { // If the computer is winning
        cout << "Computer wins!" << endl;
        gameOver = 1; // End the game
    }
}

int main() {
    cout << "Tic Tac Toe" << endl;
    TicTacToe gameBoard; // Create a game object
    gameBoard.resetBoard(); // Reset the board
    gameBoard.displayBoard(); // Display the board
    gameBoard.decideFirstPlayer(); // Decide who goes first
    while (gameBoard.gameOver == 0) { // While the game is still ongoing
        if (gameBoard.currentPlayer == 0) { // If it's the player's turn
            cout << "Player's turn" << endl;
            int col; // Column
            int row; // Row
            do { // Keep getting a new spot until an open spot is found
                cout << "Pick column: "; cin >> col; // Get column
                cout << "Pick row: "; cin >> row; // Get row
            } while (gameBoard.validateMove(col, row) == 0);
            gameBoard.displayBoard(); // Display the board
            gameBoard.checkForWinner(); // Check for a winner
            if (gameBoard.gameOver == 0) { // If the game is not over, switch to computer
                gameBoard.currentPlayer = 1; // Switch turn to computer
                gameBoard.switchPlayer(); // Switch active player
            }
        } else if (gameBoard.currentPlayer == 1) { // If it's the computer's turn
            cout << "Computer's turn" << endl;
            srand(time(0)); // Seed the random number generator
            int col, row;
            do { // Keep getting a new spot until an open spot is found
                col = (rand() % 3) + 1;
                row = (rand() % 3) + 1;
            } while (gameBoard.validateMove(col, row) == 0);
            cout << "Computer moves to (" << col << ", " << row << ")" << endl; // Show computer's move
            gameBoard.displayBoard(); // Display the board
            gameBoard.checkForWinner(); // Check for a winner
            if (gameBoard.gameOver == 0) { // If the game is not over, switch to player
                gameBoard.currentPlayer = 0; // Switch turn to player
                gameBoard.switchPlayer(); // Switch active player
            }
        }
    }
    return 0; // End of the program
}