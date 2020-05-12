#include <iostream>
using namespace std;

class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(){
        n=2;
        A=new int[2];
    }
    Diagonal(int no){
        n=no;
        A=new int[(no*(no+1))/2];
    }
    ~Diagonal(){
        delete []A;
    }
    void Set(int i,int j, int x){
        if(i>=j){
            A[(i*(i-1)/2)+j-1]=x;
        }
    } 
    int Get(int i,int j){
        if(i>=j){
            return A[(i*(i-1)/2)+j-1];
        }else{
            return 0;
        }
    }
    void Display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j){
                    cout<<A[(i*(i-1)/2)+j-1]<<" ";
                }else{
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main() {
	Diagonal d(4);
	d.Set(1,1,5);
	d.Set(2,1,4);
        d.Set(2,2,6);
	d.Set(3,1,9);
	d.Set(3,2,1);
	d.Set(3,3,2);
	d.Set(4,1,1);
	d.Set(4,2,8);
	d.Set(4,3,7);
	d.Set(4,4,3);
	d.Display();
	return 0;
}
