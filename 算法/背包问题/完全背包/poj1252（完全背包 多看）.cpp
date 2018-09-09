#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int dp[2101];
int main()
{
	int t;
	int val[7];
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<6;i++){
			scanf("%d",&val[i]);
		}
		memset(dp,100,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<6;i++){
			for(int j=val[i];j<=2000;j++){
				dp[j]=min(dp[j],dp[j-val[i]]+1);
			}
		}
		
		for(int i=0;i<6;i++){
			for(int j=2000;j>=0;j--){
				dp[j]=min(dp[j],dp[j+val[i]]+1);
			}
		}
		
		int sum=0;
		int maxn=0;
		for(int i=1;i<=100;i++){
			sum+=dp[i];
			if(dp[i]>maxn) maxn=dp[i];
		}
		
		printf("%.2lf %d\n",sum/100.0,maxn);
	}	
} 
