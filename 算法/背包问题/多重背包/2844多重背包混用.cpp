#include<bits/stdc++.h>
using namespace std;
#define M(a,b) memset(a,b,sizeof(a));
#define INF -0x3f3f3f3f
int val[1001],num[1001],dp[100005],n,m;

void bag01(int cost,int weight){
	for(int i=m;i>=cost;i--){
		dp[i] = max(dp[i],dp[i-cost]+weight);
	}
}

void wbag(int cost,int weight){
	for(int i=cost;i<=m;i++){
		dp[i] = max(dp[i],dp[i-cost]+weight);
	}
}

void MultipleBag(int cost,int weight,int amount){
	if(cost*amount >=m) wbag(cost,weight);
	else{
		int k=1;
		while(k<amount){
			bag01(k*cost,k*weight);
			amount-=k;
			k*=2;
			//k<<=1;
			//二进制左移动一位
			//比如 5 的二进制 101 左移动变成 1010 = 10; 
		}
		if(amount>0)bag01(amount*cost,amount*weight);
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0) break;
		M(val,0);
		M(num,0);
		for(int i=1;i<=m;i++) dp[i]=INF;
		dp[0]=0;
		int maxn=0;
		for(int i=1;i<=n;i++) scanf("%d",&val[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			maxn+=(val[i]*num[i]);
		}
		m = min(maxn,m);
		for(int i=1;i<=n;i++){
			MultipleBag(val[i],val[i],num[i]);
		}
		int ans=0;
		for(int i=0;i<=m;i++){
			if(dp[i]>0) ans++;
		}
		printf("%d\n",ans);
	}		
} 
