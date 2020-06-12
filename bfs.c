#include <stdio.h>
#include <stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};
void create(struct Queue *q,int s){
        q->front=q->rear=-1;
        q->size=s;
        q->Q=(int *)malloc(s*sizeof(int));
    }
void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1)
    printf("queue is full\n");
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear)
    printf("queue is empty\n");
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int isempty(struct Queue *q){
    return q->front==q->rear;
}
void BFS(int i,int n,int A[][8]){
    struct Queue q;
    create(&q,n);
    int visited[9] ={0,0,0,0,0,0,0,0,0};
    int u;
    printf("%d ",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isempty(&q)){
        u=dequeue(&q);
        for(int v=1;v<=n;v++){
            if(A[u][v]==1 && visited[v]==0){
                printf("%d ",v);
                visited[v]=1;
                enqueue(&q,v);
            }
        }
    }
}

int main() {
	int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    BFS(1,8,A);
	return 0;
}
