#include <iostream>
using namespace std;

/* Function: displayBoard
   Purpose : Display the current state of the 3x3 Tic-Tac-Toe board.
*/
void displayBoard(char board[3][3]) {
    cout << "\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

/* Function: makeMove
   Purpose : Try to place 'x' or 'o' in the given row/col.
             Returns true if successful, false if invalid.
*/
bool makeMove(char board[3][3], int row, int col, char symbol) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid position! Try again.\n";
        return false;
    }
    if (board[row][col] != ' ') {
        cout << "That cell is already occupied! Try again.\n";
        return false;
    }
    board[row][col] = symbol;
    return true;
}

/* Function: checkWin
   Purpose : Check all rows, columns, and diagonals for a win.
*/
bool checkWin(char board[3][3], char symbol) {
    // Check rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;

    // Check columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return true;

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;

    return false;
}

/* Function: isDraw
   Purpose : Returns true if all cells are filled and no winner.
*/
bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

/* Function: playTicTacToe
   Purpose : Handles the game loop, switching players, and displaying results.
*/
void playTicTacToe() {
    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    char player1 = 'x';
    char player2 = 'o';
    char currentPlayer = player1;

    cout << "\n Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1: x   |   Player 2: o\n";

    while (true) {
        displayBoard(board);
        int row, col;

        cout << "\nPlayer " << (currentPlayer == 'x' ? "1 (x)" : "2 (o)") << ", enter your move (row and column 1-3): ";
        cin >> row >> col;

        // Adjust for 0-indexing
        row--; col--;

        if (!makeMove(board, row, col, currentPlayer))
            continue; // Invalid move → ask again

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "\n Player " << (currentPlayer == 'x' ? "1 (x)" : "2 (o)") << " wins the game!\n";
            break;
        }

        if (isDraw(board)) {
            displayBoard(board);
            cout << "\n Game drawn!\n";
            break;
        }

        // Switch turns
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
}

/* -------- MAIN FUNCTION -------- */
int main() {
    char again;
    do {
        playTicTacToe();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for playing!\n";
    return 0;
}
