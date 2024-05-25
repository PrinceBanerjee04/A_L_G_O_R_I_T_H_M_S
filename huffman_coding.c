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
