//finding missing element when starting element is not 1 and two or more continuous are missing
//procedure 3
//scan through array
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n],k=0;
	int diff;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    diff=arr[i]-k;
	    
	    while(diff>arr[0]){
	    cout<<"Missing element is "<<arr[0]+k<<endl;
	    k++;
	    diff--;
	    }
	    k++;
	}

	return 0;
}
