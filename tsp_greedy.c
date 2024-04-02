
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

void nearestNeighbor(int** graph, int* path, int n) {
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int currentCity = 0; // Start from city 0
    path[0] = 0;
    visited[0] = 1;

    for (int i = 1; i < n; i++) {
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
