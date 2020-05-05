//finding duplicates in sorted array
//procedure 4
//hash table/bitset
#include <iostream>
using namespace std;

int main() {
	int n,count=0;
	cin>>n;
	int arr[n];
	int l=1, h=12;
	int H[h+1];
	for(int i=0;i<=h;i++){
	    H[i]=0;
	}
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    if(H[arr[i]]==0){
	        H[arr[i]]=1;
	    }else if(H[arr[i]]==1){
	        cout<<"Duplicate element is "<<arr[i]<<endl;
	        count++;
	        H[arr[i]]++;
	    }
	}
	cout<<count;
	return 0;
}
