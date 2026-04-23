// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// // - YES if cycle exist

#include <stdio.h>

#define V 4

int dfs(int graph[V][V], int node, int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(graph, i, visited, recStack))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0;  // remove from recursion stack
    return 0;
}

int hasCycle(int graph[V][V]) {
    int visited[V] = {0};
    int recStack[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return 1;
        }
    }
    return 0;
}

int main() {
    int graph[V][V] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {1,0,0,0}  // cycle
    };

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}