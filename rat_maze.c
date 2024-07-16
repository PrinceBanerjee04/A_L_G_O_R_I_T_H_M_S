#include <stdio.h>
#include <stdbool.h>

#define N 4 // Define the size of the maze

// Function to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Function to check if x, y is a valid move
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
