//finding missing element
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	int sum=0,sum1;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    sum+=arr[i];
	}
	sum1=(arr[n-1]*(arr[n-1]+1))/2;
	cout<<"Missing element is "<<sum1-sum;
	return 0;
}
