#include<bits/stdc++.h>
using namespace std;
int dp[3000100];
int Max(int a,int b)
{
    return (a>b?a:b);
}
int main()
{
	double q;
	int n;
	int m[1001];
	double mo;
	char s;
	int n1;
	int max;
	while(scanf("%lf%d",&q,&n)!=EOF)
	{
		if(n==0) break;
		max=(int)(q*100);
		int index=1;
		memset(dp,0,sizeof(dp));
		memset(m,0,sizeof(m));
		for(int i=0;i<n;i++)
		{
			int flag=0;
			int sum=0;
			scanf("%d",&n1);
			int a,b,c;
			a=b=c=0;
			for(int j=0;j<n1;j++)
			{
				scanf("%*c%c:%lf",&s,&mo);
				int x=(int)(mo*100);
				if(s=='A') a+=x;
				else if(s=='B') b+=x;
				else if(s=='C') c+=x;
				else flag=1;
			}
 			if(a>60000 || b>60000 || c>60000) flag=1;
 			sum=(a+b+c);
			if(sum>100000) flag=1;
			if(flag==0) m[index++]=sum;	
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=index+1;i++)
		{
			for(int j=max;j>=m[i];j--)
			{
				dp[j]=Max(dp[j],dp[j-m[i]]+m[i]);
			}
		}
		printf("%.2lf\n",dp[max]/100.0);
	}
} 
