//sin series
#include <iostream>
using namespace std;

double T1(int x,int n){// n is factorial highest power of x
    static double s=1;
    if(n<=1){
        return x*s;
    }else{
        s=1-(x*x*s/(n*(n-1)));
        //cout<<s<<endl;
        return T1(x,n-2);
    }
}

int main() {

	cout<<T1(3,3);
	return 0;
}
