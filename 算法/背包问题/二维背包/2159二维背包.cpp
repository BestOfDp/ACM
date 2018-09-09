#include<bits/stdc++.h>
using namespace std;
int dp[300][1000];
int main()
{
	int n,m,k,s;
	int v[101];
	int w[101];
	while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
	{
		for(int i=1;i<=k;i++)
		{
			scanf("%d %d",&v[i],&w[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int q=1;q<=k;q++)
		{
			for(int i=1;i<=s;i++)
			{
				for(int j=w[q];j<=m;j++)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-w[q]]+v[q]);
				}
			}	
		}
		int temp=1;
		for(int i=1;i<=m;i++)
		{
			if(dp[s][i]>=n)
			{
				printf("%d\n",m-i);
				temp=0;
				break;
			}
		}
		if(temp) printf("-1\n");
	}
}
