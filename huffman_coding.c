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

// Function to swap two nodes in the priority queue
void swapNode(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Standard min heapify function
void minHeapify(PriorityQueue* queue, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < queue->size && queue->array[left]->freq < queue->array[smallest]->freq)
        smallest = left;

    if (right < queue->size && queue->array[right]->freq < queue->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&queue->array[smallest], &queue->array[idx]);
        minHeapify(queue, smallest);
    }
}

// Check if size of heap is 1
int isSizeOne(PriorityQueue* queue) {
    return queue->size == 1;
}

// Extract minimum node from priority queue
Node* extractMin(PriorityQueue* queue) {
    Node* temp = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    minHeapify(queue, 0);
    return temp;
}

// Insert a new node into priority queue
void insertNode(PriorityQueue* queue, Node* node) {
    ++queue->size;
    int i = queue->size - 1;
    while (i && node->freq < queue->array[(i - 1) / 2]->freq) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}
