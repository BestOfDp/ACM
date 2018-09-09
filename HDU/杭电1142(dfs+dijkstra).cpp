#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
int mat[1001][1001];
int dis[1001];
int vis[1001];
int dp[1001];
int n,m;
int dfs(int x)
{
	int sum=0;
	if(dp[x]!=-1) return dp[x];
	if(x==2) return 1;
	for(int i=1;i<=n;i++)
	{
		if(mat[x][i]<INF && dis[i]<dis[x] && i!=x)
		{
			sum+=dfs(i);
		}
	}
	dp[x]=sum;
	return dp[x];
}
int main()
{
	int a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) mat[i][j]=0;
				else mat[i][j]=INF;
			}
		memset(vis,0,sizeof(vis));
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c<mat[a][b]) 
			{
				mat[a][b]=c;
				mat[b][a]=c;	
			} 
		}
		for(int i=1;i<=n;i++) dis[i]=mat[2][i];
		vis[2]=1;
		
		for(int i=1;i<n;i++)
		{
			int min1=INF;
			int pos=-1;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==0 && dis[j]<min1)
				{
					min1=dis[j];
					pos=j;
				}
			}
			if(pos==-1) break;
			vis[pos]=1;
			for(int j=1;j<=n;j++)
			{
				if(mat[pos][j]<INF)
				{
					dis[j]=min(dis[j],dis[pos]+mat[pos][j]);	
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(1));
	}
} 
