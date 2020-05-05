//find pair with sum k
#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin>>k>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(arr[j]==(k-arr[i])){
	            cout<<arr[i]<<" + "<<arr[j]<<" = "<<k<<endl;
	        }
	    }
	}
	//cout<<count;
	return 0;
}
