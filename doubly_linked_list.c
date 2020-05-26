#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
int count(struct Node *p){
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index <0 )//   || index >count() 
        return;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    t->prev=NULL;
    if(index==0)
        {
        t->next=first;
        first->prev=t;
        first=t;
        }
    else
        {
        for(int i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next)p->next->prev=t;
        p->next=t;
        }
}
int deleting(struct Node *p,int position){
    int x;
    if(position<1){
        return -1;
    }
    if(position==1){
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
        return x;
    }else{
        for(int i=1;i<position;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
        x=p->data;
        free(p);
        return x;
    }
}
void reverse(struct Node *p){
    struct Node *temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->next;
        if(p->next==NULL)first=p;
    }
}

int main(){
    int A[]={3,5,7,31,25,28,32,42};
    create(A,8);
    display(first);
    Insert(first,2,9);
    display(first);
    deleting(first,2);
    display(first);
    return 0;
}





