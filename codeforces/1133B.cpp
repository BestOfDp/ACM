#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		a[temp%k]++;
	}	
	int ans = 0;
//	cout << a[0] << endl;
	for(int i=0;i<=k/2;i++){
		if(i==0 || (k%2==0 && i==k/2)){
			ans += (a[i]/2)*2;
		}else{
			ans += min(a[i],a[k-i]) * 2;
		}
	}
	cout << ans << endl;
} 
