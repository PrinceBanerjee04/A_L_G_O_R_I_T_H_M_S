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

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST() {
    Edge result[numNodes];
    int e = 0;
    int i = 0;

    qsort(edges, numEdges, sizeof(Edge), compare);

    Subset* subsets = (Subset*)malloc(numNodes * sizeof(Subset));

    for (int v = 0; v < numNodes; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < numNodes - 1 && i < numEdges) {
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in MST:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d\n", result[i].src, result[i].dest);
    }

    free(subsets);
}
