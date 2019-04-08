#include<bits/stdc++.h>
using namespace std;
int a[10005];
int vis[200005];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			vis[a[i]+a[j]]++;
		}
	}
	int ans=0;
	for(int i=0;i<2*1e5;i++){
		ans = max(ans,vis[i]);
	}
	cout << ans/2 << endl;
} 
