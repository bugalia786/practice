/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>vec;
	char c;
	int num,sum,max,min;
	sum=0;
	//max=0;
	do{
	    cout<<endl;
	    cout<<"P - Print numbers"<<endl;
	    cout<<"A - Add a number"<<endl;
	    cout<<"M - Display mean of the numbers"<<endl;
	    cout<<"S - Display the smallest number"<<endl;
	    cout<<"L - Display the largest number"<<endl;
	    cout<<"Q - Quit"<<endl;
	    cout<<"Enter your choice: "<<endl;
	    cin>>c;
	    if(c=='P'||c=='p'){
	        if(vec.size()==0){
	            cout<<"[] - the list is empty"<<endl;
	        }else{
	            cout<<"[ ";
	            for(unsigned int v=0;v<vec.size();v++){
	                cout<<vec[v]<<" ";
	            }
	            cout<<"]"<<endl;
	        }
	    }else if(c=='a'||c=='A'){
	        cout<<"Enter an integer: ";
	        cin>>num;
	        sum+=num;
	        vec.push_back(num);
	        cout<<num<<" added"<<endl;
	    }else if(c=='m'||c=='M'){
	        if(vec.size()==0){
	            cout<<"Unable to calculate the mean - no data"<<endl;
	        }else{
	            int l=vec.size();
	            cout<<"Mean = "<<sum/l<<endl;
	        }
	    }else if(c=='s'||c=='S'){
	        if(vec.size()==0){
	            cout<<"Unable to determine the smallest number - list is empty"<<endl;
	        }else{
	            min = vec[0];
	            for(unsigned int v=1;v<vec.size();v++){
	                if(vec[v]<min){
	                    min=vec[v];
	                }
	            }
	            cout<<"The smallest number is "<<min<<endl;
	        }
	    }else if(c=='l'||c=='L'){
	        if(vec.size()==0){
	            cout<<"Unable to determine the largest number - list is empty"<<endl;
	        }else{
	            max = vec[0];
	            for(unsigned int v=1;v<vec.size();v++){
	                if(vec[v]>max){
	                    max=vec[v];
	                }
	            cout<<"The largest number is "<<max<<endl;
	        }
	    }else if(c=='q'||c=='Q'){
	        cout<<"Goodbye"<<endl;
	    }else{
	        cout<<"Unknown selection, please try again"<<endl;
	    }
	}while(c !='q' && c !='Q');
	return 0;
}
