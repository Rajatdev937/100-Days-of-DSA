// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm). 
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Queue
int queue[MAX];
int front = 0, rear = -1;

// In-degree array
int indegree[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
void initGraph(struct Graph* g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
        indegree[i] = 0;
    }
}

// Add edge u -> v
void addEdge(struct Graph* g, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    indegree[v]++; // increase in-degree
}

// Queue operations
void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

// Kahn's Algorithm
void topologicalSort(struct Graph* g) {
    // Step 1: Push all nodes with indegree 0
    for (int i = 0; i < g->V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        // Reduce indegree of neighbors
        struct Node* temp = g->adj[u];
        while (temp != NULL) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) {
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }

    // Cycle detection
    if (count != g->V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

// Main
int main() {
    struct Graph g;
    initGraph(&g, 6);

    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);

    topologicalSort(&g);

    return 0;
}