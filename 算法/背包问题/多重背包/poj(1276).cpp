#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int dp[1000100],num[500],val[500],n,m;

void bag01(int value){
	for(int i=n;i>=value;i--){
		dp[i]=max(dp[i],dp[i-value]+value); 
	}
}

void wbag(int value){
	for(int i=value;i<=n;i++){
		dp[i]=max(dp[i],dp[i-value]+value);
	}
}

void MultipleBag(int value,int amount){
	if(value*amount>=n) wbag(value);
	else{
		int k=1;
		while(k<amount){
			bag01(value*k);
			amount-=k;
			k<<=1;
		}
		if(amount>0) bag01(value*amount);
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&num[i],&val[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			MultipleBag(val[i],num[i]);
		}
		printf("%d\n",dp[n]);
	}
} 
