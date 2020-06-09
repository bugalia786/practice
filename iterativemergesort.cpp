//iterative Merge sort
#include <iostream>
using namespace std;
void display(int *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
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
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2){
        for(i=0;i<n;i=i+p){
            l=i;
            h=i+p-1;
            if(h>=n){
                h=n-1;
            }
            mid=(l+h)/2;
            MergeSingle(A,l,mid,h);
        }
        //display(A,7);
    }
    if(p/2<n){
        MergeSingle(A,0,p/2-1,n-1);
    }
}

int main() {
	int A[]={1,17,5,15,7,4,3};
 	int a[]={1,17,5,15,7,4,3,6};
 	int B[]={3,7,4,1,5,9};
 	int D[7]={1,4,6,2,3,7,8};
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
