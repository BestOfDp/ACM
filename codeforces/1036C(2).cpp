#include<bits/stdc++.h>
using namespace std;
int a[20];
long long dp[20][10];
long long dfs(int pos,int num,bool lim){
	if(pos<0 && num>=0) return 1;
	if(pos<0 || num<0) return 0;
	if(!lim && dp[pos][num]!=-1) return dp[pos][num];
	int up = lim ? a[pos]:9;
	long long ans=0;
	for(int i=0;i<=up;i++){
		if(i==0) ans+= dfs(pos-1,num,lim && i==a[pos]);
		else ans+= dfs(pos-1,num-1,lim && i==a[pos]);
	}
	if(!lim) dp[pos][num]=ans;
	return ans;
}
long long solve(long long x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10; 
	}
	return dfs(pos-1,3,true);
}
int main()
{
	int t;
	cin >> t;
	long long x,y;
	while(t--){
		cin >> x >> y;
		memset(dp,-1,sizeof(dp));
		cout << solve(y)-solve(x-1) << endl; 
	}
} 
