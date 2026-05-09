// roblem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

#include <stdio.h>

#define INF 999999

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[100][100];

    // initialize graph
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // input edges
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[100] = {0};

    visited[1] = 1;

    int edges = 0;
    int total = 0;

    while(edges < n - 1)
    {
        int min = INF;
        int x = -1, y = -1;

        for(int i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(int j = 1; j <= n; j++)
                {
                    if(!visited[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;
        total += min;
        edges++;
    }

    printf("%d\n", total);

    return 0;
}