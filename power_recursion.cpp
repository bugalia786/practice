//power
#include <iostream>
using namespace std;

int pow1(int m,int n){
    if(n==0){
        return 1;
    }else{
        return pow1(m,n-1)*m;
    }
}
int pow2(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0)
    return pow2(m*m,n/2);
    else
    return m*pow2(m*m,(n-1)/2);
}

int main() {
	//cout<<pow1(2,3);
	cout<<pow2(2,3);
	return 0;
}
