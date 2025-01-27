#include <stdio.h>

char board[3][3];  // 3x3 Tic-Tac-Toe board

// Function to initialize the board with numbers
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check for a win
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1; // Column win
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1; // Diagonal win

    return 0;
}

// Function to check if the board is full (draw condition)
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Empty space found, not a draw
            }
        }
    }
    return 1; // No empty spaces, it's a draw
}

// Function to take player input
void playerInput(int player) {
    int choice;
    char mark = (player == 1) ? 'X' : 'O'; // Player 1 gets 'X', Player 2 gets 'O'

    while (1) {
        printf("Player %d (%c), enter a position (1-9): ", player, mark);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid position! Please enter a number between 1 and 9.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
            break;
        } else {
            printf("Position already taken! Try again.\n");
        }
    }
}

int main() {
    int player = 1; // Player 1 starts
    int gameOver = 0;

    initializeBoard();

    while (!gameOver) {
        printBoard();
        playerInput(player);

        if (checkWin()) {
            printBoard();
            printf("Player %d wins!\n", player);
            gameOver = 1;
        } else if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            player = (player == 1) ? 2 : 1; // Switch players
        }
    }

    return 0;
}
