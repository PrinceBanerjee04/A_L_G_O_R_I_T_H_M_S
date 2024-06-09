// DYNAMIC PROGRAMMING
#include <stdio.h>
#include <limits.h>

#define V 100 // Define the maximum number of vertices

void floydWarshall(int graph[V][V], int numVertices) 
{
    int dist[V][V];
    // Initialize the solution matrix same as the input graph matrix.
    for (int i = 0; i < numVertices; i++) 
    {
        for (int j = 0; j < numVertices; j++) 
        {
            dist[i][j] = graph[i][j];
        }
    }

// Add all vertices one by one to the set of intermediate vertices.
    for (int k = 0; k < numVertices; k++) {
        // Pick all vertices as source one by one.
        for (int i = 0; i < numVertices; i++) {
            // Pick all vertices as destination for the above picked source.
            for (int j = 0; j < numVertices; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j].
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

// Print the shortest distance matrix.
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numVertices;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[V][V];

    printf("Enter the adjacency matrix (use %d for infinity):\n", INT_MAX);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, numVertices);
    return 0;
}
