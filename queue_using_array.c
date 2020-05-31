#include <stdio.h>
#include<stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};
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

int main() {
	struct Queue q;
	scanf("%d",&q.size);
	q.Q=(int *)malloc(q.size*sizeof(int));
	q.front=q.rear=-1;
	printf("%d \n",dequeue(&q));
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	enqueue(&q,6);
	printf("%d \n",dequeue(&q));
	return 0;
}
