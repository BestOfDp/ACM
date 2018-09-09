#include<bits/stdc++.h>
#define INF 1 
using namespace std;
double dp[100010];
int main()
{
	int n,m;
	double weight[100001];
	double val[100001];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0) break;
		for(int i=1;i<=m;i++)
		{
			scanf("%lf%lf",&weight[i],&val[i]);	
		}	
	  	for(int i=0;i<=n;i++)
            dp[i] = INF;
	 	for(int i=1;i<=m;i++)
		 {
            for(int j=n;j>=weight[i];j--)
			{
                dp[j] = min(dp[j],dp[j-(int)weight[i]]*(1-val[i]));
            }
        }
		printf("%.1lf%%\n",(1-dp[n])*100);
	}	
} 
