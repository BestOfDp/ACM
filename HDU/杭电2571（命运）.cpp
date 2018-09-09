#include<bits/stdc++.h>
using namespace std;
int main()
{
	__int64 map[30][1500];
	__int64 dp[30][1500];
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%I64d",&map[i][j]);
			}
		}
		
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				dp[i][j]=-1000000000;
			}
		}
		
		dp[1][1]=map[1][1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<j;k++)
				{
					if(j%k==0) dp[i][j]=max(dp[i][j],dp[i][k]+map[i][j]);
				}
				dp[i][j]=max(dp[i][j],dp[i][j-1]+map[i][j]);
				dp[i][j]=max(dp[i][j],dp[i-1][j]+map[i][j]);
			}
		}
		printf("%I64d\n",dp[n][m]);
	}
}
