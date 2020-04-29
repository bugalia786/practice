//Fibonacci series
#include <iostream>
using namespace std;

int F[10];

int fib1(int n){
    if(n<=1){
        return n;
    }else{
        return fib1(n-1)+fib1(n-2);
    }
}
int fib2(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }else{
        if(F[n-2]==-1)
        F[n-2]=fib2(n-2);
        if(F[n-1]==-1)
        F[n-1]=fib2(n-1);
        return F[n-1]+F[n-2];
    }
}

int main() {
    int i;
    for(int i=0;i<10;i++){
        F[i]=-1;
    }
	cout<<fib2(5);
	return 0;
}
