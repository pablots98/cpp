#include <iostream>

char board[3][3]; // The Tic-Tac-Toe board

void initializeBoard() {
    // Initialize the board with numbers 1-9
    char initial = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = initial++;
        }
    }
}

void displayBoard() {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j];
            if (j < 2) std::cout << " |";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---|---|---\n";
    }
    std::cout << "\n";
}

bool isMoveValid(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = player;
}

bool checkWin(char player) {
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        } 
    }
    return true;
}

void playGame() {
    initializeBoard();
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        displayBoard();
        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;

        while (move < 1 || move > 9 || !isMoveValid(move)) {
            std::cout << "Invalid move. Try again: ";
            std::cin >> move;
        }

        makeMove(move, currentPlayer);

        if (checkWin(currentPlayer)) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (isDraw()) {
            displayBoard();
            std::cout << "The game is a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    playGame();
    return 0;
}

