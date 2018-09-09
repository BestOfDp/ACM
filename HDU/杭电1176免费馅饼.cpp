#include<bits/stdc++.h>
using namespace std;
int dp[100010][11];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		int a,b;
		memset(dp,0,sizeof(dp));
		int t=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			dp[b][a]++;
			t=max(t,b);
		}
		
		for(int i=t-1;i>=0;i--)
		{
			for(int j=0;j<=10;j++)
			{
				if(j==0)
				{
					dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
				}
				else if(j==10)
				{
					dp[i][j]+=max(dp[i+1][j],dp[i+1][j-1]);
				}
				else
				{
					dp[i][j]+=max(max(dp[i+1][j],dp[i+1][j+1]),dp[i+1][j-1]); 
				}
			}
		}
		printf("%d\n",dp[0][5]);
	}
}
