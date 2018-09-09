#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int dp[105];
int n,m,i,j,k;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 &&m==0) break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			for(j=m;j>=0;j--)
			{
				for(k=1;k<=j;k++)
				{
					dp[j]=max(dp[j],dp[j-k]+a[i][k]);
				}
			}
		}
		printf("%d\n",dp[m]);
	}
} 
