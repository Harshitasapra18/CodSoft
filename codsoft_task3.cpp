#include <iostream>
using namespace std;

void displayBoard(char *board) {
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    cout << "||_\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    cout << "||_\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
}

void playerMove(char *board, char player) {
    int position = -1;
    while (position < 0 || position > 8 || board[position] != ' ') {
        cout << "Player " << (player == 'X' ? '1' : '2') << ", enter your move (1-9): ";
        cin >> position;
        position--;
        if (position < 0 || position > 8 || board[position] != ' ') {
            cout << "Invalid move! Try again.\n";
        }
    }
    board[position] = player;
}

bool isWinner(char *board, char player) {
    bool winConditions[8] = {
        (board[0] == player && board[1] == player && board[2] == player),
        (board[3] == player && board[4] == player && board[5] == player),
        (board[6] == player && board[7] == player && board[8] == player),
        (board[0] == player && board[3] == player && board[6] == player),
        (board[1] == player && board[4] == player && board[7] == player),
        (board[2] == player && board[5] == player && board[8] == player),
        (board[0] == player && board[4] == player && board[8] == player),
        (board[2] == player && board[4] == player && board[6] == player)
    };
    for (bool condition : winConditions) {
        if (condition) return true;
    }
    return false;
}

bool isDraw(char *board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') return false;
    }
    return true;
}

int main() {
    char ans;
    do {
        char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char currentPlayer = 'X';
        bool gameRunning = true;

        displayBoard(board);

        while (gameRunning) {
            playerMove(board, currentPlayer);
            displayBoard(board);

            if (isWinner(board, currentPlayer)) {
                cout << "Player " << (currentPlayer == 'X' ? '1' : '2') << " wins!" << "\n";
                gameRunning = false;
            } else if (isDraw(board)) {
                cout << "It's a draw!" << "\n";
                gameRunning = false;
            }

            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }

        cout << "Do you wish to play another game? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'y');


    return 0;
}
