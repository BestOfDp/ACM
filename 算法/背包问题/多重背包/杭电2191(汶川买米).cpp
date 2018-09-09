#include<bits/stdc++.h>
using namespace std;
int dp[100005],cost[500],weight[500],num[500],n,m;

void bag01(int cost,int weight){
	for(int i=n;i>=cost;i--){
		dp[i]=max(dp[i],dp[i-cost]+weight); 
	}
}

void wbag(int cost,int weight){
	for(int i=cost;i<=n;i++){
		dp[i]=max(dp[i],dp[i-cost]+weight);
	}
}

void MultipleBag(int cost,int weight,int amount){
	if(cost*amount >=n ) wbag(cost,weight);
	else{
		int k=1;
		while(k<amount){
			bag01(k*cost,k*weight);
			amount -= k;
			k<<=1;
		}
		if(amount>0) bag01(cost*amount,weight*amount);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&cost[i],&weight[i],&num[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++) MultipleBag(cost[i],weight[i],num[i]);
		printf("%d\n",dp[n]);
	}	
} 
