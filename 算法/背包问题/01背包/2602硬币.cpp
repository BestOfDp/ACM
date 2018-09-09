#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int  Max(int a,int b)
{
	return (a>b ? a:b);
}
int dp[3000100];
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	int max;
	int v[1001];
	int w[1001];
	while(t--)
	{
		scanf("%d %d",&n,&max);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=max;j>=w[i];j--)
			{
				dp[j]=Max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		printf("%d\n",dp[max]);
	} 
} 
