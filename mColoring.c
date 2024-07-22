#include <stdio.h>
#include <stdbool.h>

#define V 4
void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
