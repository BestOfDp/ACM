#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int main()
{
	int n;
	cin >> n;
	int ans=-1;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		m[t]++;
		ans = max(ans,m[t]);
	}
	cout << ans << endl;
 } 
