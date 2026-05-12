// Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

// Input:
// - First line: integer n representing the number of vertices
// - Next n lines: n space-separated integers representing the adjacency matrix of the graph
//   (use -1 to indicate no direct edge between two vertices)

// Output:
// - Print the shortest distance matrix where the value at row i and column j represents the shortest distance from vertex i to vertex j

// Example:
// Input:
// 4
// 0 5 -1 10
// -1 0 3 -1
// -1 -1 0 1
// -1 -1 -1 0

// Output:
// 0 5 8 9
// -1 0 3 4
// -1 -1 0 1
// -1 -1 -1 0

// Explanation:
// The Floyd-Warshall algorithm works 
// by considering each vertex as an intermediate point and updating the
//  shortest paths between all pairs of vertices. For example, the shortest path from 
//  vertex 1 to vertex 3 is improved via vertex 2 with total cost 8. This process is repeated for
//   all vertices, resulting in the final shortest distance matrix.


#include <stdio.h>

#define INF 99999
#define MAX 100

void floydWarshall(int graph[MAX][MAX], int n) {

    // Using each vertex as intermediate
    for (int k = 0; k < n; k++) {

        // Source vertex
        for (int i = 0; i < n; i++) {

            // Destination vertex
            for (int j = 0; j < n; j++) {

                // Avoid overflow and update shortest path
                if (graph[i][k] != INF &&
                    graph[k][j] != INF &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {

                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (graph[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int graph[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);

            // Convert -1 to INF except diagonal
            if (graph[i][j] == -1 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph, n);

    return 0;
}