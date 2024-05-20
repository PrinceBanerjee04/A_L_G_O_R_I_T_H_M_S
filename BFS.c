#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of nodes in the graph
#define MAX_NODES 100

// Graph adjacency matrix
int graph[MAX_NODES][MAX_NODES];
// Array to track visited nodes
bool visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

// Function to add a node to the queue
void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int node = queue[front];
    front++;
    return node;
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

void bfs(int start, int numNodes) {
    visited[start] = true;
    enqueue(start);

    while (!isQueueEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
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

    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    bfs(startNode, numNodes);
    printf("\n");

    return 0;
}
