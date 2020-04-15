/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int index;
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"zxcvbnmASDFGHJKLqwertyuiopZXCVBNMasdfghjklQWERTYUIOP"};
    string str,str1,str2;
    cout<<"Write secret message:"<<endl;
    getline(cin,str);
    str1=str;
    str2=str;
    cout<<"Encrypted message...."<<endl<<endl;
    for(int i=0;i<str1.size();i++){
        if(isalpha(str1[i])){
            index=alphabet.find(str1[i]);
            str1[i]=key[index];
        }
    }
    cout<<"Encrypted message = "<<str1<<endl<<endl;
    cout<<"Decrypted message...."<<endl<<endl;
    for(int i=0;i<str2.size();i++){
        if(isalpha(str2[i])){
            index=key.find(str2[i]);
            str2[i]=alphabet[index];
        }
    }
    cout<<"Decrypted message = "<<str2<<endl<<endl;
    return 0;
}
