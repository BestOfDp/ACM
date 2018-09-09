#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int cost[100],val[100],dp[1000500];
int main()
{
	int t;
	int m,y,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&y);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&cost[i],&val[i]);
			cost[i]/=1000;
		}
		memset(dp,0,sizeof(dp));
		for(int k=0;k<y;k++){
			int s=m/1000;
			for(int i=1;i<=n;i++){
				for(int j=cost[i];j<=s;j++){
					dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
			}
		}
		m+=dp[s];
	}
		printf("%d\n",m);
	} 
} 
