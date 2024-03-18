#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int calculateDistance(int** graph, int* path, int n) {
    int distance = 0;
    for (int i = 0; i < n - 1; i++) {
        distance += graph[path[i]][path[i + 1]];
    }
    distance += graph[path[n - 1]][path[0]]; // Return to the starting city
    return distance;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int** graph, int* path, int start, int n, int* minDistance, int* minPath) {
    if (start == n - 1) {
        int distance = calculateDistance(graph, path, n);
        if (distance < *minDistance) {
            *minDistance = distance;
            for (int i = 0; i < n; i++) {
                minPath[i] = path[i];
            }
        }
        return;
    }
    for (int i = start; i < n; i++) {
        swap(&path[start], &path[i]);
        permute(graph, path, start + 1, n, minDistance, minPath);
        swap(&path[start], &path[i]); // Backtrack
    }
}
