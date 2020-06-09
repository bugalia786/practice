#include <iostream>
#include <cmath>
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
void Insert(Node **ptr,int x,int value){
    Node *temp=new Node;
    temp->data=value;
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
int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}
int Delete(Node **ptr,int x){
    Node *p=ptr[x];
    ptr[x]=ptr[x]->next;
    int r=p->data;
    delete p;
    return r;
}
void radixsort(int *A,int n){
    int max=max_function(A,n);
    int count=countDigits(max);
    Node **bin=new Node* [n];
    for(int i=0;i<n;i++){
        bin[i]=nullptr;
    }
    int j=0,digit;
    //cout<<count<<"    ";
    while(count){
        for(int i=0;i<n;i++){
            digit=(A[i]/(int)pow(10,j))%10;
            //cout<<digit<<" ";
            Insert(bin,digit,A[i]);
        }
        
        int k=0;
        for(int i=0;i<n;i++){
            while(bin[i]!=nullptr){
                A[k++]=Delete(bin,i);
                
            }
        }
        count--;
        j++;
        //cout<<endl;
    }
}
void display(int *A,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int A[]={237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
	radixsort(A,10);
	display(A,10);
	return 0;
}
