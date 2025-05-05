#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100  // Maximum number of vertices

// Find the vertex with minimum distance value, from the set of vertices not yet included
int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// Print the shortest distances from the source
void printSolution(int dist[], int n, int src) {
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Dijkstra's single-source shortest path algorithm
void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];        // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V];     // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;  // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);

        sptSet[u] = true;  // Mark the picked vertex as processed

        // Update dist[] of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n, src);
}

int main() {
    int n, src;
    int graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}






Enter number of vertices: 5
Enter the adjacency matrix (0 if no edge):
0 10 3 0 0
0 0 1 4 0
0 4 0 8 2
0 0 0 0 7
0 0 0 0 0
Enter the source vertex (0 to 4): 0
