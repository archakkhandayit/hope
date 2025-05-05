#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];
int n, e;

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal() {
    int i, count = 0, totalWeight = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, e, sizeof(Edge), compare);

    printf("Edge \tWeight\n");
    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            unionSets(u, v);
            totalWeight += edges[i].weight;
            count++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter each edge (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal();

    return 0;
}
