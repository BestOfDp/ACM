#include<bits/stdc++.h>
using namespace std;
int a[10]; // ´æ´¢Î»Êý 
int dp[20][2];
int dfs(int pos,int sta,bool lim){
	if(pos<0) return 1;
	if(!lim && dp[pos][sta]!=-1) return dp[pos][sta]; 
	int up = lim ? a[pos] : 9 ,ret=0;
	for(int i=0;i<=up;i++){
		if( (sta && i==2) || i==4) continue;
		ret += dfs(pos-1,i==6,lim && i==a[pos]);
	}
	if(!lim) dp[pos][sta]=ret;
	return ret;
}
int slove(int x){
	int pos = 0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,true);
}
int main()
{
	int x,y;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d %d",&x,&y)!=EOF){
		if(x==0 && y==0) break;
		printf("%d\n",slove(y)-slove(x-1));
	}	
} 
