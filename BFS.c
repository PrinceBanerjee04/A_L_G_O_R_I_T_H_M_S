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
void enqueue(int node) 
{
    if (rear == MAX_NODES - 1) 
    {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

// Function to remove and return a node from the queue
int dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int node = queue[front];
    front++;
    return node;
}

bool isQueueEmpty() 
{
    return front == -1 || front > rear;
}

// BFS function to traverse the graph from a start node
void bfs(int start, int numNodes) 
{
    visited[start] = true;    // Mark the start node as visited
    enqueue(start);    // Enqueue the start node

    while (!isQueueEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        // Iterate through all possible nodes
        for (int i = 0; i < numNodes; i++) {
            // If there is an edge and the node is not visited
            if (graph[currentNode][i] && !visited[i]) {
                visited[i] = true;     // Mark the node as visited
                enqueue(i);    // Enqueue the node
            }
        }
    }
}

int main() 
{
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < numEdges; i++) 
    {
        int node1, node2;
        scanf("%d %d", &node1, &node2);    // Read each edge
        // Populate the adjacency matrix for an undirected graph
        graph[node1][node2] = graph[node2][node1] = 1;
    }

    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    bfs(startNode, numNodes);    // Perform BFS starting from the start node
    printf("\n");

    return 0;
}
