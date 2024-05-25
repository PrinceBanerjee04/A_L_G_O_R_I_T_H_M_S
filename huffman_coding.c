// GREEDY METHOD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

// Structure for priority queue
typedef struct PriorityQueue {
    unsigned size;
    unsigned capacity;
    Node** array;
} PriorityQueue;

// Function to create a new node
Node* newNode(char data, unsigned freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create a priority queue
PriorityQueue* createPriorityQueue(unsigned capacity) {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (Node**)malloc(queue->capacity * sizeof(Node*));
    return queue;
}
