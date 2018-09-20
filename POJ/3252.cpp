#include<stdio.h> 
#include<string.h>
int a[100];
long long dp[100][100][100];

long long dfs(int pos,int zero,int one,int done,bool lim){
	if(pos<0) return zero >= one;
	if(!lim && dp[pos][zero][one]!=-1) return dp[pos][zero][one];
	int up = lim ? a[pos] : 1;
	long long ans=0;
	for(int i=0;i<=up;i++){
		int k = done || (i==1);
		ans += dfs(pos-1,k ? zero+(i==0):0,k ? one+(i==1):0,k,lim && i == a[pos]);
	}
	if(!lim) dp[pos][zero][one]=ans;
	return ans;
}
long long solve(long long x){
	int pos = 0;
	while(x){
		a[pos++]=x%2;
		x/=2;
	}
	return dfs(pos-1,0,0,0,true);
}
int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",solve(b)-solve(a-1));	
} 
