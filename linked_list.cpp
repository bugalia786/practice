#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
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
int Rcount(struct Node *p)
{
    if(p!=NULL)
    return Rcount(p->next)+1;
    else
    return 0;
}
int sum(struct Node *p){
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p){
    if(p==NULL)
    return 0;
    else
    return Rsum(p->next)+p->data;
}
int max(struct Node *p){
    int m=p->data;
    while(p!=NULL)
    {
        if(m<p->data){
         m=p->data;
        }
        p=p->next;
    }
    return m;
}
int min(struct Node *p){
    int m=p->data;
    while(p!=NULL)
    {
        if(m>p->data){
            m=p->data;
        }
        p=p->next;
    }
    return m;
}
int linearSearch(struct Node *p,int key){
    while(p!=NULL){
        if(p->data==key){
            printf("key found\n");
            return 1;
        }
        p=p->next;
    }
    printf("key not found\n");
    return 0;
}
struct Node* search(struct Node *p,int key){
    struct Node *q=NULL;
    while(p!=NULL){
        if(p->data==key){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
            q=p;
            p=p->next;
    }
    return NULL;
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void Insert(struct Node *p,int key,int position){
    struct Node *q=(struct Node*)malloc(sizeof(struct Node));
    q->data=key;
    q->next=first;
    first=q;
}
void Insert_position(struct Node *p,int key,int position){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=key;
    int i=1;
    while(i<position-1){
        p=p->next;
        i++;
    }
    t->next=p->next;
    p->next=t;
}
void Insert_in_sorted(struct Node *p,int key){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=key;
    struct Node *q=NULL;
    if(key<p->data){
        t->next=first;
        first=t;
    }else{
    while(p!=NULL && p->data<key){
        q=p;
        p=p->next;
    }
    t->next=q->next;
    q->next=t;
    }
}
int deleting(struct Node *p,int position){
    struct Node *q=NULL;
    struct Node *t=first;
    int x;
    if(position<1){
        return -1;
    }
    if(position==1){
        first=p->next;
        x=t->data;
        free(t);
        return x;
    }else{
        for(int i=1;i<position;i++){
            q=t;
            t=t->next;
        }
        q->next=t->next;
        x=t->data;
        free(t);
        return x;
    }
}
int check_sorted(struct Node *p){
    struct Node *q=NULL;
        q=p;
        p=p->next;
    while(p!=NULL){
        if(q->data>p->data){
            printf("not sorted\n");
            return 0;
        }
        q=p;
        p=p->next;
    }
    printf("sorted\n");
    return 1;
}
void deleting_duplicates(struct Node *p){
    struct Node *q=NULL;
    q=p;
    p=p->next;
    int a=0;
    while(p!=NULL){
        if(q->data==p->data){
            q->next=p->next;
            free(p);
            p=p->next;
            
            printf("Duplicate found %d\n",q->data);
            a++;
        }else{
        q=p;
        p=p->next;
        }
    }
    if(!a){
        printf("Duplicate not found.\n");
    }
}

int main(){
    int A[]={3,3,5,7,7,7,31,25,28,32,42};
    create(A,11);
    printf("count %d\n",count(first));
    printf("sum %d\n",sum(first));
    printf("max %d\n",max(first));
    printf("min %d\n",min(first));
    linearSearch(first,10);
    linearSearch(first,4);
    struct Node *p=search(first,8);
    display(p);
    display(first);
    search(first,9);
    display(first);
    Insert(first,9,0);
    display(first);
   // Insert_position(first,15,10);
   // display(first);
    Insert_in_sorted(first,2);
    display(first);
    deleting(first,1);
    printf("\n");
    display(first);
    deleting(first,1);
    display(first);
    check_sorted(first);
    deleting_duplicates(first);
    display(first);
    return 0;
}





