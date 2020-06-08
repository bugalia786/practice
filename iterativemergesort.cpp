//iterative Merge sort
#include <iostream>
using namespace std;
void MergeSingle(int *a,int low,int mid,int high){
    int i=low,j=mid+1,k=low,b[high+1];
    while(i<=mid && j<=high){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    for(;i<=mid;i++){ b[k++]=a[i]; }
    for(;j<=high;j++){ b[k++]=a[j]; }
    for (int i=low; i<=high; i++){
        a[i] = b[i];
    }
}
void iterative_merge_sort(int *A,int n){
    int p,l,h,mid;
    for(p=2;p<=n;p=p*2){
        for(int i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            MergeSingle(A,l,mid,h);
        }
    }
    if(p/2<n){
        MergeSingle(A,0,p/2-1,n);
    }
}
void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main() {
	int A[]={1,17,5,15,7,4,3};//output 1 4 5 7 3 1 15   Why is it so?.......
	int a[]={1,17,5,15,7,4,3,6};//output 1 3 4 5 6 7 15 17 
	int B[]={3,7,4,1,5,9};//output 1 3 4 5 7 9
	int D[7]={1,4,6,2,3,7,8};//output 1 2 3 4 6 7 8
	iterative_merge_sort(A,7);
	display(A,7);
	iterative_merge_sort(a,8);
	display(a,8);
	iterative_merge_sort(B,6);
	display(B,6);
	iterative_merge_sort(D,7);
	display(D,7);
	return 0;
}
