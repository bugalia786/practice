//taylor series
#include <iostream>
using namespace std;

double T(int x,int n){
    static double p=1, f=1;
    double r;
    if(n==0){
        return 1;
    }else{
        r=T(x,n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
}

int main() {
	//cout<<pow1(2,3);
	cout<<T(3,10);
	return 0;
}
