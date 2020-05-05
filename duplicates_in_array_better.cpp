//finding duplicates in sorted array
//procedure 2
#include <iostream>
using namespace std;

int main() {
	int n,count=0;
	cin>>n;
	int arr[n];
	int last_duplicate=0;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    if(arr[i]==arr[i-1] && arr[i]!=last_duplicate){
	        cout<<"Duplicate element is "<<arr[i]<<endl;
	        last_duplicate=arr[i];
	        count++;
	    }
	}
	cout<<count;
	return 0;
}
