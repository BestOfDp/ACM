#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int cmp2(int a,int b)
{
  return a>b;
}

__int64 a[100005];
__int64 b[100005];
__int64 dp[100005];
__int64 dp1[100005];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[i]=a[i]; 
	}
	sort(b,b+n);
	memset(dp,0,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+a[i-1];
	}
	for(int i=1;i<=n;i++)
	{	
		dp1[i]=dp1[i-1]+b[i-1];
	}
	int m;
	cin >> m;
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y >> z;
		__int64 sum=0;
		if(x==1)
		{
			sum = dp[z] - dp[y-1];
		}
		else
		{
			sum = dp1[z] - dp1[y-1];
		}
		cout << sum << endl;
	}
}
