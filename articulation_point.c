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

// Create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize a graph with given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));
    graph->discovery_time = (int*)malloc(numVertices * sizeof(int));
    graph->low_time = (int*)malloc(numVertices * sizeof(int));
    graph->visited = (bool*)malloc(numVertices * sizeof(bool));
    graph->is_articulation_point = (bool*)malloc(numVertices * sizeof(bool));
    graph->time = 0;

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
        graph->discovery_time[i] = -1;
        graph->low_time[i] = -1;
        graph->visited[i] = false;
        graph->is_articulation_point[i] = false;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
