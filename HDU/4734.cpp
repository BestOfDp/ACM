#include<bits/stdc++.h>
using namespace std;
int a[20];
int dp[20][5000];
int maxn;
int dfs(int pos,int sta,bool lim){
	if(pos<0) return sta>=0;
	if(sta<0) return 0;
	if(!lim && dp[pos][sta]!=-1) return dp[pos][sta];
	int up = lim ? a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		ans += dfs(pos-1,sta-i*(1<<(pos)),lim && i==a[pos]);
	}
	if(!lim) dp[pos][sta]=ans;
	return ans;
}
int solve(int x){
	int pos =0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,maxn,true);
}
int main()
{
	int t;
	int index=1;
	scanf("%d",&t);
	int x,y;
	memset(dp,-1,sizeof(dp));
	while(t--){
		scanf("%d %d",&x,&y);
		maxn = 0;
		int cnt=0;
		while(x){
			maxn += (x%10)*(1<<(cnt++));
			x/=10;
		}
		printf("Case #%d: %d\n",index++,solve(y)); 
	}	
} 
