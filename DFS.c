#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];    // Adjacency matrix to represent the graph
int visited[MAX_NODES];            // Array to keep track of visited nodes
int numNodes;                     // Number of nodes in the graph

// Depth First Search (DFS) function to traverse the graph
void dfs(int node) 
{
    printf("%d ", node);    // Print the current node
    visited[node] = 1;    // Mark the current node as visited

    // Traverse all nodes connected to the current node
    for (int i = 0; i < numNodes; i++) 
    {
        if (graph[node][i] && !visited[i]) 
        {
            dfs(i);
        }
    }
}

int main() 
{
    int numEdges;
    int startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < numEdges; i++) 
    {
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
