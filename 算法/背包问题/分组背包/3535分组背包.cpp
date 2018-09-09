#include<bits/stdc++.h>
using namespace std;
int dp[200][200];
int n,T,m,s;
int pos; //已取组数
int cost,val;

//至少取1 
void pack1()
{
	int i,j;
	memset(dp+pos+1,0x80,sizeof(dp[0]));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&cost,&val);
		for(j=T;j>=cost;j--)
		{
			int tmp;
			tmp=max(dp[pos+1][j],dp[pos][j-cost]+val);
			dp[pos+1][j]=max(dp[pos+1][j],dp[pos+1][j-cost]+val);
			dp[pos+1][j]=max(dp[pos+1][j],tmp);
				
		}	
	}	
	pos++;
} 

//最多取1
void pack2()
{
	int i,j;
	memcpy(dp+pos+1,dp+pos,sizeof(dp[0]));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&cost,&val);
		for(j=T;j>=cost;j--)
		{
			dp[pos+1][j]=max(dp[pos+1][j],dp[pos][j-cost]+val);	
		}	
	}	
	pos++;
} 

void pack3()
{
	int i,j;
	memcpy(dp+pos+1,dp+pos,sizeof(dp[0]));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&cost,&val);
		for(j=T;j>=cost;j--)
		{
			dp[pos+1][j]=max(dp[pos+1][j],dp[pos+1][j-cost]+val);
		}
	}
	pos++;
}
int main()
{
	int i;
	while(scanf("%d%d",&n,&T)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		pos=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&m,&s);
			switch(s)
			{
				case 0:pack1();break;
				case 1:pack2();break;
				case 2:pack3();break;	
			}
		}	
		dp[n][T]=max(dp[n][T],-1);
		printf("%d\n",dp[n][T]);
	}	
} 
