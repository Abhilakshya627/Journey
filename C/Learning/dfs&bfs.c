#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("\nQueue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
        return -1;
    } else {
        vertex = queue[front++];
        if (front > rear)
            front = rear = -1;
        return vertex;
    }
}

void push(int vertex) {
    if (top == MAX - 1)
        printf("\nStack Overflow\n");
    else
        stack[++top] = vertex;
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    } else
        return stack[top--];
}

void bfs(int startVertex, int n) {
    int i, vertex;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front != -1) {
        vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int startVertex, int n) {
    int i, vertex;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    push(startVertex);
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    while (top != -1) {
        vertex = stack[top];
        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
                printf("%d ", i);
                break;
            }
        }
        if (i == n)
            pop();
    }
}

int main() {
    int n, i, j, choice, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    while (1) {
        printf("\nMenu:\n");
        printf("1. BFS\n");
        printf("2. DFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the starting vertex: ");
                scanf("%d", &startVertex);
                printf("BFS Traversal: ");
                bfs(startVertex, n);
                printf("\n");
                break;
            case 2:
                printf("Enter the starting vertex: ");
                scanf("%d", &startVertex);
                printf("DFS Traversal: ");
                dfs(startVertex, n);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited; // Array to track visited vertices
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    if (!graph) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    if (!graph->adjLists || !graph->visited) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Initialize all vertices as unvisited
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) implementation
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex); // Print the visited vertex

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            DFS(graph, temp->vertex); // Recursive call for unvisited adjacent vertices
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS) implementation
void BFS(Graph* graph, int startVertex) {
    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1; // Mark the starting vertex as visited
    queue[rear++] = startVertex; // Enqueue the starting vertex

    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue a vertex
        printf("%d ", currentVertex); // Print the visited vertex

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            if (!graph->visited[temp->vertex]) {
                graph->visited[temp->vertex] = 1; // Mark as visited
                queue[rear++] = temp->vertex; // Enqueue the adjacent vertex
            }
            temp = temp->next;
        }
    }

    free(queue); // Free the allocated memory for the queue
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

// Main function
int main() {
    int vertices = 7; // Number of vertices
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

*/