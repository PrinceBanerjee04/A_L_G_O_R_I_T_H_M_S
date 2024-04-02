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

int* mergePaths(int* path1, int n1, int* path2, int n2, int** graph, int* minDistance) {
    int* mergedPath = (int*)malloc((n1 + n2) * sizeof(int));

    for (int i = 0; i < n1; i++) {
        mergedPath[i] = path1[i];
    }

    for (int i = 0; i < n2; i++) {
        mergedPath[n1 + i] = path2[i];
    }

    // Find the shortest edge between the two halves
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int newDistance = graph[path1[i]][path2[j]] + graph[path1[(i + 1) % n1]][path2[(j + 1) % n2]];
            if (newDistance < *minDistance) {
                *minDistance = newDistance;
                // Reorder the merged path accordingly
                for (int k = 0; k <= i; k++) {
                    swap(&mergedPath[k], &mergedPath[n1 + j]);
                    j = n2;
                }
            }
        }
    }

    return mergedPath;
}
