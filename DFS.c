#include <stdio.h>
#include <stdlib.h>

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int numNodes;

void dfs(int node) 
{
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}
int main() {
    int numEdges;
    int startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = graph[node2][node1] = 1;
    }

    printf("Enter the start node: ");
    scanf("%d", &startNode);

    printf("DFS traversal starting from node %d: ", startNode);
    dfs(startNode);
    printf("\n");

    return 0;
}
