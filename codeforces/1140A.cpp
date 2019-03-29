#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n ;
	int a[10005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}	
	int ans = 0 ;
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn = max(maxn,a[i]);
		if(maxn == i ){
			ans++;
		}
	}
	cout << ans << endl;
} 
