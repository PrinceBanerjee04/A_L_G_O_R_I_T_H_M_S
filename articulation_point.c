// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Adjacency list
typedef struct {
    Node* head;
} AdjList;
