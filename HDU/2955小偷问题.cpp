#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	double p;
	int n;
	int i,j;
	int m[105];
	double p1[10001];
	double dp[10000];
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		scanf("%lf %d",&p,&n);
		double pmax=1-p;
		memset(m,0,sizeof(m));
		memset(p1,0,sizeof(p1));
		for(i=1;i<=n;i++)
		{
			scanf("%d %lf",&m[i],&p1[i]);
			sum+=m[i];
			p1[i]=1-p1[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(i=1;i<=n;i++)
		{
			for(int j=sum;j>=m[i];j--)
			{
				dp[j]=max(dp[j],dp[j-m[i]]*p1[i]); 
			}
		}
		for(i=sum;i>=0;i--)
		{
			if(dp[i]>=pmax) break;
		}
		printf("%d\n",i);
	}
} 
