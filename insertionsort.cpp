//insertion sort
#include <iostream>
using namespace std;

/*void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}*/

void insertionsort(int *A,int n){
    int temp;
    for(int i=0;i<n;i++){
        temp=A[i];
        for(int j=i-1;j>=0;j--){
            if(A[j]>temp){
                A[j+1]=A[j];
            }else{
                A[j+1]=temp;
                break;
            }
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
	int A[]={2,5,4,8,6,9,1};
	insertionsort(A,7);
	display(A,7);
	return 0;
}
