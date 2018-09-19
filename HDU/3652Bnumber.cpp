#include<bits/stdc++.h>
using namespace std;
int a[20];
int dp[20][20][3][15];
		//	位数   %13    是否有13  上一位  
int dfs(int pos,int mod,int done,int pre,bool lim){
	if(pos<0) return done && (!mod);
	if(!lim && dp[pos][mod][done][pre]!=-1) return dp[pos][mod][done][pre];
	int up = lim ? a[pos]:9,ans=0;
	for(int i=0;i<=up;i++){
		ans += dfs(pos-1,(mod*10+i)%13,done || (pre==1 && i==3),i,lim && i==a[pos]);
	}
	if(!lim) dp[pos][mod][done][pre]=ans;
	return ans; 
}
int solve(int x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,0,0,true);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(n));
	}
} 
