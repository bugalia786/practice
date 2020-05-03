//Linear_search
#include <iostream>
using namespace std;

int Linear_search(int *arr,int length,int key){
    for(int i=0;i<length;i++){
        if(arr[i]==key){
            cout<<"Yes we found it"<<endl;
            return i;
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
void insert(int *arr,int index,int x,int &length){
    for(int i=length;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=x;
    length++;
}
void Delete(int *arr,int index,int &length){
    for(int i=index;i<length-1;i++){
        arr[i]=arr[i+1];
    }
    length--;
}

int main() {
	int arr[10]={1,2,3,4,5};
	int length=5;
	int index, x;
	index=2;
	x=6;
	display(arr,length);
	insert(arr,index,x,length);
	display(arr,length);
	Delete(arr,index,length);
	display(arr,length);
	cout<<Linear_search(arr,length,3);
	return 0;
}
