#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	int n;
	cin >> n;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		ans = max(ans,a+b);
	}	
	cout << ans << endl;
} 
