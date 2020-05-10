//find whether two strings are anagram
#include <iostream>
#include <string>
using namespace std;


int find_anagram(string s,string str){//for strings with all elmemts in lower case
    int H[26]={0};
    char c;
    if(s.size()!=str.size()){
        cout<<"both can't be anagram since length is not same"<<endl;
        return 0;
    }else{
    for(int i=0;i<s.size();i++){
        H[s[i]-'a']++;
    }
    for(int i=0;i<str.size();i++){
        if(H[str[i]-'a']<1){
            cout<<"strings are not anagram"<<endl;
            return 0;
        }else{
            H[str[i]-'a']--;
        }
    }
    }
    cout<<"Both strings are anagram"<<endl;
    return 1;
}
int find_anagram2(string s,string str){//for strings with all elmemts in lower case and it does not tell how many times it is repeating
    long int H =0,x=0;//all elements should be different
    if(s.size()!=str.size()){
        cout<<"both can't be anagram since length is not same"<<endl;
        return 0;
    }else{
    for(int i=0;i<s.size();i++){
        x=1;
        x=x<<(s[i]-97);
        H=(x|H);
    }
    for(int i=0;i<str.size();i++){
        x=1;
        x=x<<(str[i]-97);
        if((x&H)==0){
            cout<<"strings are not anagram"<<endl;
            return 0;
        }
    }
    }
    cout<<"Both strings are anagram"<<endl;
    return 1;
}

int main() {
	string s;
	string str;
	getline(cin,s);
	getline(cin, str);
    find_anagram2(s,str);
	return 0;
}
