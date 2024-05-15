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
        // Check if there is an edge between the current node and node i, and if node i has not been visited
        if (graph[node][i] && !visited[i]) 
        {
            dfs(i);    // Recursively call DFS on node i
        }
    }
}

int main() 
{
    int numEdges;    // Number of edges in the graph
    int startNode;  // Starting node for DFS traversal

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

    // Input the start node for DFS traversal
    printf("Enter the start node: ");
    scanf("%d", &startNode);

    // Perform DFS traversal starting from the specified start node
    printf("DFS traversal starting from node %d: ", startNode);
    dfs(startNode);
    printf("\n");

    return 0;
}
