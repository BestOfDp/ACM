#include<bits/stdc++.h>
using namespace std;
char s1[] = "~!@#$%^&*()_+`1234567890-=QWERTYUIOP{}|qwertyuiop[]\\ASDFGHJKL:\"asdfghjkl;'ZXCVBNM<>?zxcvbnm,./";
char s2[] = "~!@#$%^&*(){}`1234567890[]\"<>PYFGCRL?+|',.pyfgcrl/=\\AOEUIDHTNS_aoeuidhtns-:QJKXBMWVZ;qjkxbmwvz";

map<char,char>m;

int main()
{
	for(int i=0;i<strlen(s1);i++){
		m[s1[i]] = s2[i];
	}
	string s;
	while(getline(cin,s)){
		for(int i=0;i<s.size();i++){
			if(m.find(s[i])!=m.end()){
				printf("%c",m[s[i]]);
			}else{
				printf("%c",s[i]);
			}	
		}
		cout << endl;
	}
}
