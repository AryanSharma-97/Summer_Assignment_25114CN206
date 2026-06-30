#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // 3x3

//initialize the board
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}
// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

//check if someone has won
char checkWin() {
    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];

    // Columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; // No winner yet
}

// Function to check if board is full (draw)
int isFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void playerMove() {
    int row, col;
    do {
        printf("Enter your move (row and column: 0-2): ");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = 'X';
}

void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
    printf("Computer placed O at (%d, %d)\n", row, col);
}

int main() {
    srand(time(0));
    initBoard();
    char winner = ' ';

    printf("Welcome to Tic-Tac-Toe!\nYou are X, Computer is O.\n");
    displayBoard();

    while (winner == ' ' && !isFull()) {
        playerMove();
        displayBoard();
        winner = checkWin();
        if (winner != ' ' || isFull()) break;

        computerMove();
        displayBoard();
        winner = checkWin();
    }

    if (winner == 'X')
        printf("Congratulations! You win!\n");
    else if (winner == 'O')
        printf("Computer wins! Better luck next time.\n");
    else
        printf("It's a draw!\n");

    return 0;
}
