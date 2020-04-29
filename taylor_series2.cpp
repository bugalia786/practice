//taylor series
#include <iostream>
using namespace std;

double T1(int x,int n){
    static double s=1;
    if(n==0){
        return s;
    }else{
        s=1+(x*s/n);
        return T1(x,n-1);
    }
}

int main() {
	//cout<<pow1(2,3);
	cout<<T1(3,10);
	return 0;
}
