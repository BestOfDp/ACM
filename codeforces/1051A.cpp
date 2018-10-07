#include<bits/stdc++.h>
using namespace std;
int d[1000],u[1000],l[1000];
int main()
{
	int n;
	cin >> n;	
	string s;
	for(int i=0;i<n;i++){
		int low=-1,upp=-1,dig=-1;
		int cnt_d=0;
		int cnt_lower=0;
		int cnt_upper=0;
		memset(d,0,sizeof(d));
		memset(l,0,sizeof(l));
		memset(u,0,sizeof(u));
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]>='0' && s[j]<='9'){
				dig=j;
				d[++cnt_d]=j;	
			}
			if(s[j]>='a' && s[j]<='z'){
				low=j;
				l[++cnt_lower]=j;		
			}
			if(s[j]>='A' && s[j]<='Z'){
				upp=j;
				u[++cnt_upper]=j;	
			}
		}
		if(low == -1) {
			if(cnt_upper >= 2) s[u[cnt_upper--]]='a';			
			else s[d[cnt_d--]] = 'a';		
		}
		if(upp == -1) {		
			if(cnt_lower>=2) s[l[cnt_lower--]] = 'A';			
			else s[d[cnt_d--]] = 'A';		
		}		
		if(dig == -1) {			
			if(cnt_lower>=2) s[l[cnt_lower--]] = '1';			
			else s[u[cnt_upper--]] = '1';		
		}

		cout << s << endl;
	}
} 
