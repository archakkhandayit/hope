#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int visited[MAX];
int a[MAX][MAX];

void DFS(int i, int n){
    printf("%d ", i);
    visited[i] = 1;
    for(int j = 0; j < n; j++){
        if(a[i][j] == 1 && visited[j] == 0){
            DFS(j, n);
        }
    }
}

int main(){
    int n, start;
    
    printf("Enter number of nodes (max %d): ", MAX);
    scanf("%d", &n);
    if(n <= 0 || n > MAX){
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);
    if(start < 0 || start >= n){
        printf("Invalid starting node.\n");
        return 1;
    }

    // Initialize visited array to 0
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    DFS(start, n);

    return 0;
}





Enter number of nodes (max 20): 7
Enter adjacency matrix (7x7):
0 1 1 1 0 0 0
1 0 0 1 0 0 0
1 0 0 1 1 0 0
1 1 1 0 1 0 0
0 0 1 1 0 1 1
0 0 0 0 1 0 0
0 0 0 0 1 0 0
Enter starting node (0 to 6): 0
