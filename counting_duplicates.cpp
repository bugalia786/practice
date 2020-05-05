//counting duplicates in sorted array
//procedure 4
//hash table/bitset
#include <iostream>
using namespace std;

int main() {
	int n,count=0;
	cin>>n;
	int arr[n];
	int last_duplicate=0,j;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	   // if(arr[i]==arr[i-1] && arr[i]!=last_duplicate){
	     //   cout<<"Duplicate element is "<<arr[i]<<endl;
	   // last_duplicate=arr[i];
	   //     count++;
	    //}
	}
	for(int i=0;i<n;i++){
	    if(arr[i]==arr[i-1]){
	        j=i;
	        while(arr[j]==arr[i])j++;
	        cout<<arr[i]<<" is appearing "<<(j-i+1)<<" times."<<endl;
	        i=j-1;
	    }
	}
	//cout<<count;
	return 0;
}
