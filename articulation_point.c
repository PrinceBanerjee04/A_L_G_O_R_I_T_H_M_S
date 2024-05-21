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

// DFS function to find articulation points
void DFS(Graph* graph, int v, int parent) {
    graph->visited[v] = true;
    graph->discovery_time[v] = graph->low_time[v] = ++graph->time;
    int children = 0;

    for (Node* i = graph->array[v].head; i != NULL; i = i->next) {
        int u = i->vertex;

        if (!graph->visited[u]) {
            children++;
            DFS(graph, u, v);
            graph->low_time[v] = (graph->low_time[v] < graph->low_time[u]) ? graph->low_time[v] : graph->low_time[u];

            if (graph->low_time[u] >= graph->discovery_time[v] && parent != -1)
                graph->is_articulation_point[v] = true;
        }
        else if (u != parent)
            graph->low_time[v] = (graph->low_time[v] < graph->discovery_time[u]) ? graph->low_time[v] : graph->discovery_time[u];
    }

    if (parent == -1 && children > 1)
        graph->is_articulation_point[v] = true;
}
