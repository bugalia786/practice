#include <iostream>
using namespace std;
void Merge(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int p[100];
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            p[k++] = A[i++];
        else
            p[k++] = A[j++];
    }
    for(;i<=mid;i++)
        p[k++] = A[i];
    for(;j<=h;j++)
        p[k++] = A[j];
    for(int i=l;i<=h;i++)
        A[i] = p[i];
}
void RMergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}
int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    RMergeSort(A,0,n-1);
    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    return 0;

}
