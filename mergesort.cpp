//Merge sort
#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void Merge(int *a,int *b,int *c,int m,int n){
    int i,j,k;
    i=j=k=0;
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }else{
            c[k++]=b[j++];
        }
    }
    for(;i<m;i++) c[k++]=a[i];
    for(;j<n;j++) c[k++]=b[j];
}
void MergeSingle(int *a,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int b[high+1];
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){ b[k++]=a[i++];}
    while(j<=high){ b[k++]=a[j++];}
    for (int i=low; i<=high; i++){
        a[i] = b[i];
    }
}

void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int A[]={1,3,5,7,10,15,17};
	int B[]={2,6,9,11,13,18};
	int C[13];
	int D[7]={1,4,6,7,2,3,8};
	Merge(A,B,C,7,6);
	display(C,13);
	MergeSingle(D,0,3,6);
	display(D,7);
	return 0;
}
