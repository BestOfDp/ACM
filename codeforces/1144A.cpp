#include<bits/stdc++.h>
using namespace std;
int vis[10000];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		string s;
		cin >> s;
		int min1 = 30;
		for(int j=0;j<s.size();j++){
			vis[s[j]-'a']++;
			min1 = min(min1,s[j]-'a');
		}
		string ans = "Yes";
		for(int j=0;j<s.size();j++){
			if(vis[j+min1]!=1){
				ans = "No";
			}
		}
		cout << ans << endl;
	}	
}
