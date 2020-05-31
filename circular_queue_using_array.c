#include <stdio.h>
#include<stdlib.h>

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};
void enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size==q->front)
    printf("queue is full\n");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear)
    printf("queue is empty\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int main() {
	struct Queue q;
	scanf("%d",&q.size);
	q.Q=(int *)malloc(q.size*sizeof(int));
	q.front=q.rear=0;
	printf("%d \n",dequeue(&q));
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	printf("%d \n",dequeue(&q));
	enqueue(&q,5);
	printf("%d \n",dequeue(&q));
	enqueue(&q,6);
	
	return 0;
}
