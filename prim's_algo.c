// ADJACENCY MATRIX
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];
int key[MAX_NODES];
bool mstSet[MAX_NODES];

int minKey(int numNodes) 
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < numNodes; v++) 
    {
        if (mstSet[v] == false && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int numNodes) 
{
    printf("Edge   Weight\n");
    for (int i = 1; i < numNodes; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int numNodes) 
{
    for (int i = 0; i < numNodes; i++) 
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numNodes - 1; count++) 
    {
        int u = minKey(numNodes);

        mstSet[u] = true;

        for (int v = 0; v < numNodes; v++) 
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(numNodes);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Minimum Spanning Tree:\n");
    primMST(numNodes);

    return 0;
}
