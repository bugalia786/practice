//Tower of Hanoi 
#include <iostream>
using namespace std;

void toh(int n, char a, char b, char c){
    if(n>0){
        toh(n-1,a,c,b);
        cout<<"From "<<a<<" to "<<c<<endl;
        toh(n-1,b,a,c);
    }
}

int main() {
	toh(3,'A','B','C');
	return 0;
}
