#include<bits/stdc++.h>
using namespace std;
int a[20];
int dp[20][20];
long long dfs(int pos,int num,bool lim){
	if(pos<0) return 1;
	if(num >= 0 && !lim && dp[pos][num]!=-1) return dp[pos][num];
	int up = lim ? a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		if(abs(num-i)<=1) continue;
		int pre = i;
		if(i==0 && num==-2) pre=-2;
		ans += dfs(pos-1,pre,lim && i==a[pos]);
	}
	if(num>=0 && !lim) dp[pos][num]=ans;
	return ans;
}
long long solve(long long x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,-2,true);
}
int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",solve(y)-solve(x-1));	
} 
