#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

int graph[MAX_NODES][MAX_NODES];
int numNodes, numEdges;
