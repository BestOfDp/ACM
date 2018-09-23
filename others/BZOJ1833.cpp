#include<bits/stdc++.h>
using namespace std;
int a[20];
long long dp[20][20][20];
long long dfs(int pos,int num,int sum,int sta,bool lim){
	if(pos<0) return sum;
	if(sta && !lim && dp[pos][num][sum]!=-1) return dp[pos][num][sum];
	int up = lim ? a[pos]:9;
	long long ans=0;
	for(int i=0;i<=up;i++){
		if(i==0){
			if(sta || pos==0) ans+= dfs(pos-1,num,sum+ (num==i),sta || i,lim && i==a[pos]);
			else ans+= dfs(pos-1,num,sum,0,lim && i==a[pos]);
		}
		else ans+= dfs(pos-1,num,sum+(num==i),1,lim && i==a[pos]);
	}
	if(!lim && sta) dp[pos][num][sum]=ans;
	return ans;
}
long long solve(long long x,int num){
	if(x<0) return 0;
	if(x==0) return num==0?1:0;
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,num,0,0,true);
}
int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=8;i++){
		printf("%lld ",solve(y,i)-solve(x-1,i));
	}
	printf("%lld\n",solve(y,9)-solve(x-1,9));
} 
