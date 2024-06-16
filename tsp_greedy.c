#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

int min(int a, int b) 
{
    return (a < b) ? a : b;
}

int calculateDistance(int** graph, int* path, int n) 
{
    int distance = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        distance += graph[path[i]][path[i + 1]];
    }
    distance += graph[path[n - 1]][path[0]]; // Return to the starting city
    return distance;
}

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nearestNeighbor(int** graph, int* path, int n) 
{
    int visited[n];
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }

    int currentCity = 0; // Start from city 0
    path[0] = 0;
    visited[0] = 1;

    for (int i = 1; i < n; i++) 
    {
        int nearestCity = -1;
        int minDistance = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[currentCity][j] < minDistance) {
                minDistance = graph[currentCity][j];
                nearestCity = j;
            }
        }
        path[i] = nearestCity;
        visited[nearestCity] = 1;
        currentCity = nearestCity;
    }
}


int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            printf("Enter the distance between city %d and city %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    int* path = (int*)malloc(n * sizeof(int));

    nearestNeighbor(graph, path, n);

    printf("Shortest Hamiltonian cycle: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", path[i]);
    }
    printf("\nTotal distance: %d\n", calculateDistance(graph, path, n));

    for (int i = 0; i < n; i++) 
    {
        free(graph[i]);
    }
    free(graph);
    free(path);

    return 0;
}
