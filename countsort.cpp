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
void countsort(int *A,int n){
    int max=max_function(A,n);
    int H[max+1];
    for(int i=0;i<max+1;i++){
        H[i]=0;
    }
    for(int i=0;i<n;i++){
        H[A[i]]++;
    }
    int j=0;
    for(int i=0;i<max+1;i++){
        while(H[i]>0){
            A[j++]=i;
            H[i]--;
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
	countsort(A,10);
	display(A,10);
	return 0;
}
