#include <iostream>
using namespace std;

class Node{
public:
  Node *lchild;
  int data;
  Node *rchild;
};

class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(){
        front=rear=-1;
        size=20;
        Q=new Node*[size];
    }
    Queue(int size){
        front=rear=-1;
        this->size=size;
        Q=new Node*[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    void display();
    int isempty();
};
void Queue::enqueue(Node *x){
    if(rear==size-1){
        cout<<"queue is full"<<endl;
    }else{
        rear++;
        Q[rear]=x;
    }
}
Node *Queue::dequeue(){
    Node *x=NULL;
    if(front==rear){
        cout<<"queue is empty"<<endl;
    }else{
        front++;
        x=Q[front];
    }
    return x;
}
void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int Queue::isempty(){
    return front==rear;
}
class tree{
private:
    Node *root;
public:
    tree(){
        root=NULL;
    }
    void create_tree();
    void preorder(){
        preorder(root);
    }
    void preorder(Node *p);
    void inorder(){
        inorder(root);
    }
    void inorder(Node *p);
    void postorder(){
        postorder(root);
    }
    void postorder(Node *p);
};
void tree::create_tree(){
    Node *p,*t;
    int x;
    Queue q;
    //scan root value
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isempty()){
        p=q.dequeue();
        //enter lchild
        cin>>x;
        if(x!=-1){//-1 for null 
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        //enter rchild
        cin>>x;
        if(x!=-1){//-1 for null 
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void tree::preorder(Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::inorder(Node *p){
    if(p!=NULL){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void tree::postorder(Node *p){
    if(p!=NULL){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main() {
	tree t;
	t.create_tree();
	t.preorder();
	cout<<endl;
	t.inorder();
	cout<<endl;
	t.postorder();
	cout<<endl;
	return 0;
}
