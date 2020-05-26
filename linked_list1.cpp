#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
class Linked_list{
private:
    Node *first;
public:
    Linked_list(){first=NULL;}
    Linked_list(int A[],int n);
    ~Linked_list();
    int Length();
    void Display();
    void Insert(int index,int x);
};
Linked_list::Linked_list(int A[],int n){
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
Linked_list::~Linked_list(){
    Node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}
int Linked_list::Length(){
    Node *p=first;
    int count=0;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    return count;
}
void Linked_list::Display(){
    Node *p=first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void Linked_list::Insert(int index,int x){
    Node *p=first;
    Node *t;
    if(index <0 || index > Length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
        {
        t->next=first;
        first=t;
        }
    else
        {
        for(int i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
        }
}

int main() {
	int A[]={1,3,5,6,7,8};
	Linked_list l(A,6);
	l.Display();
	cout<<l.Length()<<endl;
	l.Insert(3,9);
	l.Display();
	return 0;
}
