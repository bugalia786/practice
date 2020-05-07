//finding length of a string
//changing case of string
//counting vowels and consonents
//no of words
//validating string/password
//reversing string using another string
//reversing string using hashtable
//comaparing strings
//palindrome
//find duplicates using hashtable
//find duplicates using bitset 
#include <iostream>
#include <string>
using namespace std;

int check_password(string st){
    for(int i=0;i<st.size();i++){
        if((st[i]>='a' && st[i]<='z')||(st[i]>='A' && st[i]<='Z')||(st[i]>='0' && st[i]<='9')){
            continue;
        }else{
            cout<<"Not a valid password"<<endl;
            return -1;
        }
    }
    cout<<"Valid password"<<endl;
    return 1;
}
void Reverse1(string &str){
    string str1;
    for(int i=str.size()-1, j=0;i>=0;i--,j++){
        str1[j]=str[i];
    }
    for(int i=0;i<str.size();i++){
        str[i]=str1[i];
    }
}
void Reverse2(string &str){
    int j=(str.size()-1);
    int i=0;
    char temp;
    while(i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}
void compare_strings(string s1, string s2){
    if(s1.compare(s2)==0){
        cout<<"Both strings are same."<<endl;
    }else if(s1.compare(s2)<0){
        cout<<"String "<<s1<<" is smaller than string "<<s2<<endl;
    }else{
        cout<<"String "<<s1<<" is larger than string "<<s2<<endl;
    }
}
int palindrome(string str){
    //one method is to reverse the string then compare original string with reverse string
    //other is comparing element from start and end
    int j=(str.size()-1);
    int i=0;
    while(i<j){
        if(str[i]!=str[j]){
            cout<<"This is not palindrome."<<endl;
            return 0;
        }
        i++;
        j--;
    }
    cout<<"This is palindrome."<<endl;
    return 1;
}
void find_duplicate1(string s){//for strings with all elmemts in lower case
    int H[26]={0};
    char c;
    for(int i=0;i<s.size();i++){
        H[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(H[i]>1){
            c='a'+i;
            cout<<"Letter "<<c<<" appears "<<H[i]<<" times."<<endl;
        }
    }
}


int main() {
	string s;
	string str;
	getline(cin,s);
	getline(cin, str);
	int length=s.size();
	int l=str.size();
	cout<<length<<endl;
	for(int i=0;i<length;i++){
	    if(s[i]>='a' && s[i]<='z'){
	        s[i]=s[i]-'a'+'A';
	    }else if(s[i]>='A' && s[i]<='Z'){
	        s[i]=s[i]-'A'+'a';
	    }
	}
	cout<<s<<endl;
	cout<<l<<endl;
	//cout<<str;
	int count_vowel=0, count_consonents=0,count_words=0;
	for(int i=0;i<l;i++){
	    if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
	        count_vowel++;
	    }else if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z')){
	        count_consonents++;
	    }else if(str[i]==' ' && str[i-1]!=' '){
	        count_words++;
	    }
	}
	cout<<str<<endl;//How Are  You
	cout<<"No of Vowels "<<count_vowel<<endl;
	cout<<"No of consonents "<<count_consonents<<endl;
	cout<<"No of words "<<count_words+1<<endl;
	string password1, password2;
	getline(cin,password1);//Abc123
	getline(cin,password2);//abr?12
	check_password(password1);
	check_password(password2);
	Reverse1(str);
	cout<<str<<endl;
	Reverse2(str);
	cout<<str<<endl;
	string s1=s;
	compare_strings(s1,s);
	compare_strings(s1,str);
	string pal,dup;
	getline(cin,pal);
	palindrome(pal);
	getline(cin,dup);
	find_duplicate1(dup);
	return 0;
}
