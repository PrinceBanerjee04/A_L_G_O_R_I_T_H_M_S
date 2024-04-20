void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}
