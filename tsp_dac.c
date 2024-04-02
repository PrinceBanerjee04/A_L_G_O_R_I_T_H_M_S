int calculateDistance(int** graph, int* path, int n) {
    int distance = 0;
    for (int i = 0; i < n - 1; i++) {
        distance += graph[path[i]][path[i + 1]];
    }
    distance += graph[path[n - 1]][path[0]]; // Return to the starting city
    return distance;
}
