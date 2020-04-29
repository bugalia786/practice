//ncr using recursion
#include <iostream>
using namespace std;


int ncr(int n,int r){//not good 
    static double s=1;
    if(r>=n){
        return 0;
    }else{
    if(r==0 ){
        return s;
    }else{
        s=s*((double)(n-r+1)/r);
        //cout<<s<<"  ";
        return ncr(n,r-1);
    }
}
}
int fact(int n){
    if(n==0) return 1;
    else return fact(n-1)*n;
}
int ncr1(int n, int r){
    int t=fact(n)/(fact(r)*fact(n-r));
    return t;
}
int ncr2(int n,int r){
    if(n<r){
        return 0;
    }
    if(n==0 ||r==0){
        return 1;
    }else{
        return ncr2(n-1,r-1)+ncr2(n-1,r);
    }
}


int main() {
	cout<<ncr(6,2)<<endl;
	cout<<ncr1(6,2)<<endl;
	cout<<ncr2(6,2)<<endl;
	return 0;
}
