#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 15

char board[MAX_N][MAX_N];
char solution[MAX_N][MAX_N];
int n;

void printSolution() {
    for (int i = 0; i < n; i++) {
        printf("%s\n", solution[i]);
    }
    printf("\n");
}

int isSafe(int row, int col) {
    // Check vertical
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return 0;
    }

    // Check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return 0;
    }

    // Check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return 0;
    }

    return 1;
}

void solve(int row) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            strcpy(solution[i], board[i]);
        }
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            solve(row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n > MAX_N || n < 1) {
        printf("Please enter a value between 1 and %d.\n", MAX_N);
        return 1;
    }

    // Initialize board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    solve(0);
    printSolution();
    return 0;
}
