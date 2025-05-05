#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue *q){
    return q->r == q->f;
}

int isFull(struct queue *q){
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    } else {
        q->f++;
        return q->arr[q->f];
    }
}

int main(){
    int n, start;

    printf("Enter number of nodes (max 20): ");
    scanf("%d", &n);
    if(n > 20 || n <= 0){
        printf("Invalid number of nodes.\n");
        return 1;
    }

    int a[20][20];
    int visited[20] = {0};

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n-1);
    scanf("%d", &start);
    if(start < 0 || start >= n){
        printf("Invalid starting node.\n");
        return 1;
    }

    struct queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    printf("%d ", start);
    visited[start] = 1;
    enqueue(&q, start);

    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j = 0; j < n; j++){
            if(a[node][j] == 1 && !visited[j]){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
  
    return 0;
}





Enter number of nodes (max 20): 7
Enter adjacency matrix:
0 1 1 1 0 0 0
1 0 0 1 0 0 0
1 0 0 1 1 0 0
1 1 1 0 1 0 0
0 0 1 1 0 1 1
0 0 0 0 1 0 0
0 0 0 0 1 0 0
Enter starting node (0 to 6): 0
