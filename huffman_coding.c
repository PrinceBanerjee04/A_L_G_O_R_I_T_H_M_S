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
Node* newNode(char data, unsigned freq) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create a priority queue
PriorityQueue* createPriorityQueue(unsigned capacity) 
{
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (Node**)malloc(queue->capacity * sizeof(Node*));
    return queue;
}

// Function to swap two nodes in the priority queue
void swapNode(Node** a, Node** b) 
{
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Standard min heapify function
void minHeapify(PriorityQueue* queue, int idx) 
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < queue->size && queue->array[left]->freq < queue->array[smallest]->freq)
        smallest = left;

    if (right < queue->size && queue->array[right]->freq < queue->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) 
    {
        swapNode(&queue->array[smallest], &queue->array[idx]);
        minHeapify(queue, smallest);
    }
}

// Check if size of heap is 1
int isSizeOne(PriorityQueue* queue) 
{
    return queue->size == 1;
}

// Extract minimum node from priority queue
Node* extractMin(PriorityQueue* queue) 
{
    Node* temp = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    minHeapify(queue, 0);
    return temp;
}

// Insert a new node into priority queue
void insertNode(PriorityQueue* queue, Node* node) 
{
    ++queue->size;
    int i = queue->size - 1;
    while (i && node->freq < queue->array[(i - 1) / 2]->freq) 
    {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}

// Function to build Huffman tree
Node* buildHuffmanTree(char data[], int freq[], int size) 
{
    Node *left, *right, *top;
    PriorityQueue* queue = createPriorityQueue(size);
    for (int i = 0; i < size; ++i)
        insertNode(queue, newNode(data[i], freq[i]));
    while (!isSizeOne(queue)) 
    {
        left = extractMin(queue);
        right = extractMin(queue);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(queue, top);
    }
    return extractMin(queue);
}

// Function to print Huffman codes from the root of Huffman tree
void printCodes(Node* root, int arr[], int top) 
{
    if (root->left) 
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) 
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) 
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman coding function
void HuffmanCodes(char data[], int freq[], int size) 
{
    Node* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_VERTICES], top = 0;
    printCodes(root, arr, top);
}

int main() 
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    printf("Huffman Codes:\n");
    HuffmanCodes(data, freq, size);
    return 0;
}
