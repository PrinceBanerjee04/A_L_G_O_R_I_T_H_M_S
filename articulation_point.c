// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Adjacency list
typedef struct {
    Node* head;
} AdjList;

// Graph structure
typedef struct {
    int numVertices;
    AdjList* array;
    int* discovery_time;
    int* low_time;
    bool* visited;
    bool* is_articulation_point;
    int time;
} Graph;
