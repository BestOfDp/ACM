#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<algorithm>
#define INF -0x3f3f3f3f
using namespace std;
int dp[100010];
struct stone
{
	int h,a,c;
}s[500];

bool cmp(stone a,stone b){
	return a.a<b.a;
}
void bag01(int value,int V){
	for(int i=V;i>=value;i--){
		dp[i]=max(dp[i],dp[i-value]+value); 
	}
}

void wbag(int value,int V){
	for(int i=value;i<=V;i++){
		dp[i]=max(dp[i],dp[i-value]+value); 
	}
}

void MultipleBag(int value,int amount,int V){
	if(value*amount>=V) wbag(value,V);
	else{
		int k=1;
		while(k<amount){
			bag01(value*k,V);
			amount-=k;
			k<<=1; 
		}
		if(amount>0) bag01(value*amount,V);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].h,&s[i].a,&s[i].c);
	}
	sort(s+1,s+n+1,cmp);
	//memset(dp,0,sizeof(dp));
	for(int i=1;i<=s[n].a;i++){
		dp[i]=INF;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		MultipleBag(s[i].h,s[i].c,s[i].a);
	}
	int max=0;
//	for(int i=0;i<100010;i++){
//		if(dp[i]>max){
//			max=dp[i];
//		}
//	}
//	printf("%d\n",max);
	for(int i=s[n].a;i>=0;i--){
		if(dp[i]>=0)
		{
			printf("%d\n",dp[i]);
			break;	
		}
	}
}
