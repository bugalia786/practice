//Quick sort
#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int partition(int *A,int l,int h){
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)swap(A[i],A[j]);
    }while(i<j);
    swap(A[l],A[j]);
    return j;
}
void Quicksort(int *A,int l,int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);
    }
}

void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int A[]={2,5,4,8,6,9,1,INT32_MAX};
	Quicksort(A,0,7);
	display(A,7);
	return 0;
}
