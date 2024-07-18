#include <stdio.h>
#include <stdbool.h>

#define N 4 // Define the size of the maze

// Function to print the solution matrix
void printSolution(int sol[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf(" %d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Function to check if x, y is a valid move
bool isSafe(int maze[N][N], int x, int y) 
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// A recursive utility function to solve the Maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) 
{
    // If x, y is the destination cell, return true
    if (x == N - 1 && y == N - 1) 
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y)) 
    {
        // Mark x, y as part of the solution path
        sol[x][y] = 1;

        // Move forward in the x direction
        if (solveMazeUtil(maze, x + 1, y, sol)) {
            return true;
        }

        // Move down in the y direction
        if (solveMazeUtil(maze, x, y + 1, sol)) {
            return true;
        }

        // If neither move is successful, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// Function to solve the Maze problem using backtracking
bool solveMaze(int maze[N][N]) {
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(sol);
    return true;
}

int main() {
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

    solveMaze(maze);
    return 0;
}
