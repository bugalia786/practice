//binary_search
#include <iostream>
using namespace std;

int binary_search(int *arr,int l,int h,int key){
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==key){
            cout<<"Yes finally found"<<endl;
            return mid;
        }else if(arr[mid]<key){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return -1;
}
int binary_search1(int *arr,int l,int h,int key){
    int mid=(l+h)/2;
    if(l<=h){
    if(arr[mid]==key){
        cout<<"Yes finally found"<<endl;
        return mid;
    }else if(arr[mid]<key){
        return binary_search1(arr,mid+1,h,key);
    }else{
        return binary_search1(arr,l,mid-1,key);
    }
    }
    return -1;
}

void display(int *arr,int length){
    cout<<endl;
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
	int arr[10]={1,2,3,4,5};
	int length=5;
	display(arr,length);
	cout<<binary_search1(arr,0,length,4);
	return 0;
}
