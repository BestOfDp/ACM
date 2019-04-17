#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int left=0;
	string ans="";
	int l=0;
	int r=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(') l++;
		else if(s[i]==')') r++;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			if(l!=n/2){
				s[i]='(';
				l++;
			}else{
				s[i]=')';
				r++;
			}
		}
	}
	stack<char>st;
	st.push(s[0]);
	for(int i=1;i<n;i++){
		if(st.empty()){
			st.push('!');
			break;
		}
		if(s[i]=='('){
			st.push('(');
		}else{
			if(st.top()=='('){
				st.pop();
			}else st.push(')');
		}
	}
	if(st.empty()){
		cout << s <<endl;
	}else cout << ":(" << endl;
}
