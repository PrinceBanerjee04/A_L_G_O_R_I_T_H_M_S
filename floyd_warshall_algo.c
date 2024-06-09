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
