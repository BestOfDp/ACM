#include<bits/stdc++.h>
using namespace std;
int dp[3000100];
int main()
{
	int n;
	int v[1001];
	int w[1001];
	int m;
	int t;
	int e,f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&e,&f);
		m=f-e;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&v[i],&w[i]);
		}
		
		//*****************��СֵֻҪ ��Ҫ��ʼ��Ϊ0���У��� 
		//0x3fҲ���� 
		memset(dp,1,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=w[i];j<=m;j++)
			{
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		//****************ע�����50001 
		if(dp[m]!=dp[50001]) printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
		
		else printf("This is impossible.\n");
	}
} 
