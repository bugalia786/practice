//selection sort
#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void selectionsort(int *A,int n){
    int j,k;
    for(int i=0;i<n-1;i++){
        j=k=i;
        while(j<n){
            if(A[j]<A[k]) k=j;
            j++;
        }
        swap(A[i],A[k]);
    }
}
void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int A[]={2,5,4,8,6,9,1};
	selectionsort(A,7);
	display(A,7);
	return 0;
}
