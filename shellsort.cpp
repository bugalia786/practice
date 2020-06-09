//shell sort
#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void shelsort(int *A,int n){
    int temp,j;
    int gap=n/2;
    while(gap>=1){
        for(int i=0;i+gap<n;i+=gap){
            if(A[i]>A[i+gap]){
                swap(A[i],A[i+gap]);
                j=i;
                while((j-gap)>=0 && A[j]<A[j-gap]){
                    swap(A[j],A[j-gap]);
                    j=j-gap;
                }
            }
        }
        //display(A,11);
        gap=gap/2;
    }
}

int main() {
	int A[]={2,5,4,8,6,9,1,16,18,3,7};
	//display(A,11);
	shelsort(A,11);
	display(A,11);
	return 0;
}
