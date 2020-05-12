#include <iostream>
using namespace std;

class Element{
public:
  int i;
  int j;
  int x;  
};
class sparse{
private:
  int m;
  int n;
  int num;
  Element *e;
public:
    sparse(int m, int n, int num){
        this->m=m;
        this->n=n;
        this->num=num;
        e=new Element[this->num];
    }
    ~sparse(){
        delete [] e;
    }
    void read(){
        for(int i=0;i<num;i++){
            cin>>e[i].i>>e[i].j>>e[i].x;
        }
    }
    void display(){
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==e[k].i && j==e[k].j){
                cout<<e[k].x<<" ";
                k++;
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}
};


int main() {
	sparse s(5,5,5);
	s.read();
	s.display();
	return 0;
}
