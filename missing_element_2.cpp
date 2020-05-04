//finding missing element when starting element is not 1 
//procedure 2
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
	    
	    if(diff!=arr[0]){
	    cout<<"Missing element is "<<arr[0]+k<<endl;
	    k++;
	    }
	    k++;
	}

	return 0;
}
