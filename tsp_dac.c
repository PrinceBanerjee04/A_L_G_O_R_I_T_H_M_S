//TRAVELLING SALESMAN PROBBELM USING DIVIDE AND CONQUER

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

int* mergePaths(int* path1, int n1, int* path2, int n2, int** graph, int* minDistance) 
{
    int* mergedPath = (int*)malloc((n1 + n2) * sizeof(int));

    for (int i = 0; i < n1; i++) 
    {
        mergedPath[i] = path1[i];
    }

    for (int i = 0; i < n2; i++) 
    {
        mergedPath[n1 + i] = path2[i];
    }

    // Find the shortest edge between the two halves
    for (int i = 0; i < n1; i++) 
    {
        for (int j = 0; j < n2; j++) {
            int newDistance = graph[path1[i]][path2[j]] + graph[path1[(i + 1) % n1]][path2[(j + 1) % n2]];
            if (newDistance < *minDistance) 
            {
                *minDistance = newDistance;
                // Reorder the merged path accordingly
                for (int k = 0; k <= i; k++) 
                {
                    swap(&mergedPath[k], &mergedPath[n1 + j]);
                    j = n2;
                }
            }
        }
    }

    return mergedPath;
}

int* tspDivideAndConquer(int** graph, int* path, int n, int* minDistance) 
{
    if (n <= 3) 
    {
        // Solve the TSP using brute force for small number of cities
        permute(graph, path, 0, n, minDistance, path);
        return path;
    }

    int mid = n / 2;
    int* path1 = tspDivideAndConquer(graph, path, mid, minDistance);
    int* path2 = tspDivideAndConquer(graph, path + mid, n - mid, minDistance);

    int* mergedPath = mergePaths(path1, mid, path2, n - mid, graph, minDistance);

    free(path1);
    free(path2);

    return mergedPath;
}


int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            printf("Enter the distance between city %d and city %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    int* path = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }

    int minDistance = INT_MAX;

    int* minPath = tspDivideAndConquer(graph, path, n, &minDistance);

    printf("Shortest Hamiltonian cycle: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", minPath[i]);
    }
    printf("\nTotal distance: %d\n", minDistance);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(path);
    free(minPath);

    return 0;
}
