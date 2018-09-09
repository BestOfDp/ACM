#include<bits/stdc++.h>
using namespace std;
#define INF -0x3f3f3f3f
int num[7],dp[1000100],n;

void bag01(int weight,int value){
	for(int i=n;i>=weight;i--){
		dp[i]=max(dp[i],dp[i-weight]+value);
	}
}

void wbag(int weight,int value){
	for(int i=weight;i<=n;i++){
		dp[i]=max(dp[i],dp[i-weight]+value);
	}
}

void MultipleBag(int weight,int value,int amount){
	if(weight*amount>=n) wbag(weight,value);
	else{
		int k=1;
		while(k<amount){
			bag01(k*weight,k*value);
			amount-=k;
			k<<=1;
		}
		if(amount>0)bag01(weight*amount,amount*value);
	}
}

int main()
{
	int num1=1;
	while(scanf("%d%d%d%d%d%d",&num[1],&num[2],&num[3],&num[4],&num[5],&num[6])!=EOF){
		if(num[1]==0 && num[2]==0 && num[3]==0 && num[4]==0 && num[5]==0 && num[6]==0) break;
		int sum=0;
		for(int i=1;i<=6;i++){
			sum+=num[i]*i;
		}
		n=sum/2;
		for(int i=1;i<=sum;i++){
			dp[i]=INF;
		}
		dp[0]=0;
		for(int i=1;i<=6;i++) MultipleBag(i,i,num[i]);
		printf("Collection #%d:\n",num1++);
		if(dp[n]==sum-n) printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
} 
