// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Undirected graph
    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Find vertex with minimum distance
int getMinVertex(int dist[], int visited[], int n) {
    int min = INF;
    int vertex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            vertex = i;
        }
    }

    return vertex;
}

// Dijkstra Algorithm
void dijkstra(int n, int source) {
    int dist[MAX];
    int visited[MAX];

    // Initialize
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Main loop
    for (int i = 1; i <= n; i++) {

        int u = getMinVertex(dist, visited, n);

        if (u == -1)
            break;

        visited[u] = 1;

        Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}