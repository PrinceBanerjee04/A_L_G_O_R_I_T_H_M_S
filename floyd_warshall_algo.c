// DYNAMIC PROGRAMMING

#include <stdio.h>
#include <limits.h>

#define V 100 // Define the maximum number of vertices

void floydWarshall(int graph[V][V], int numVertices) 
{
    int dist[V][V];
    
    for (int i = 0; i < numVertices; i++) 
    {
        for (int j = 0; j < numVertices; j++) 
        {
            dist[i][j] = graph[i][j];
        }
    }
