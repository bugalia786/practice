//finding length of a string
//changing case of string
//counting vowels and consonents
//no of words
//validating string/password
#include <iostream>
#include <string>
using namespace std;

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
	cout<<str<<endl;
	cout<<"No of Vowels "<<count_vowel<<endl;
	cout<<"No of consonents "<<count_consonents<<endl;
	cout<<"No of words "<<count_words+1<<endl;
	return 0;
}
