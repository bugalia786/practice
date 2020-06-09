//count sort
//requirement maximum should be given
#include <iostream>
using namespace std;
int max_function(int *A,int n){
    int max1=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>max1){
            max1=A[i];
        }
    }
    return max1;
}
class Node{
public:
    int data;
    Node *next;
};
void Insert(Node **ptr,int x){
    Node *temp=new Node;
    temp->data=x;
    temp->next=nullptr;
    if(ptr[x]==nullptr){
        ptr[x]=temp;
    }else{
        Node *p=ptr[x];
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=temp;
    }
}
int Delete(Node **ptr,int x){
    Node *p=ptr[x];
    ptr[x]=ptr[x]->next;
    int r=p->data;
    delete p;
    return r;
}
void binsort(int *A,int n){
    int max=max_function(A,n);
    Node **bin=new Node* [max+1];
    for(int i=0;i<max+1;i++){
        bin[i]=nullptr;
    }
    for(int i=0;i<n;i++){
        Insert(bin,A[i]);
    }
    int j=0;
    for(int i=0;i<max+1;i++){
        while(bin[i]!=nullptr){
            A[j++]=Delete(bin,i);
            
        }
    }
}
void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int A[]={6,3,9,10,15,6,8,12,3,6};
	binsort(A,10);
	display(A,10);
	return 0;
}
