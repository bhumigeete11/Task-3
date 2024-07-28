#include <iostream>

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char player = 'X';

void drawBoard() {
    std::cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j] << " |";
        }
        std::cout << "\n-------------\n";
    }
}

void playerTurn() {
    int choice;
    std::cout << "Player " << player << ", enter your move (1-9): ";
    std::cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        player = (player == 'X') ? 'O' : 'X';
    } else {
        std::cout << "Invalid move! Try again.\n";
        playerTurn();
    }
}

bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

    // Check columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    while (true) {
        drawBoard();
        playerTurn();
        if (checkWin()) {
            drawBoard();
            std::cout << "Player " << ((player == 'X') ? 'O' : 'X') << " wins!\n";
            break;
        }
        if (checkDraw()) {
            drawBoard();
            std::cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}



