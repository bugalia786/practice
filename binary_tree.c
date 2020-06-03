#include <stdio.h>
#include<stdlib.h>

struct Node{
  struct Node *lchild;
  int data;
  struct Node *rchild;
}*root=NULL;

struct Queue{
  int size;
  int front;
  int rear;
  struct Node **Q;
};
void create(struct Queue *q){
    //scanf("%d",&q.size);
    q->size=100;
	q->Q=(struct Node **)malloc(q->size*sizeof(struct
Node *));
	q->front=q->rear=-1;
}
void enqueue(struct Queue *q,struct Node *x){
    if((q->rear+1)%q->size==q->front)
    printf("queue is full\n");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q){
    struct Node * x=NULL;
    if(q->front==q->rear)
    printf("queue is empty\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isempty(struct Queue *q){
    return (q->front==q->rear);
}
void create_binary_tree(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q);
    //scan root value
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isempty(&q)){
        p=dequeue(&q);
        //enter lchild
        scanf("%d",&x);
        if(x!=-1){//-1 for null 
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        //enter rchild
        scanf("%d",&x);
        if(x!=-1){//-1 for null 
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void preorder(struct Node *t){
    if(t!=NULL){
        printf("%d ",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}




int main() {
	create_binary_tree();
	preorder(root);
	return 0;
}
