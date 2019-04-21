#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int ans;
int vis[5][5];
int n;
int flag;
void dfs(int r,int c,int sum){
	if(sum==n*4 && flag==1){
		ans++;
		return;
	} 
	if(c==4){
		dfs(r+1,0,sum);
		return;
	}
	for(int i=r;i<n;i++){
		for(int j=c;j<4;j++){
			// caocao
			if(vis[i][j]==0 && vis[i+1][j]==0 && vis[i][j+1]==0 && vis[i+1][j+1]==0 && j+1 <4 && i+1 <n && flag==0){
				vis[i][j]=1;vis[i+1][j]=1;vis[i][j+1]=1; vis[i+1][j+1]=1;flag=1;
				dfs(i,j+1,sum+4);
				vis[i][j]=0;vis[i+1][j]=0;vis[i][j+1]=0; vis[i+1][j+1]=0;flag=0;
			} 
			// jiang =
			if(vis[i][j]==0 && vis[i+1][j]==0 && j <4 && i+1 <n){
				vis[i][j]=1;vis[i+1][j]=1;
				dfs(i,j+1,sum+2);
				vis[i][j]=0;vis[i+1][j]=0;
			} 
			// jiang --
			if(vis[i][j]==0 && vis[i][j+1]==0 && j+1 <4 && i <n){
				vis[i][j]=1;vis[i][j+1]=1;
				dfs(i,j+1,sum+2);
				vis[i][j]=0;vis[i][j+1]=0;
			} 
			// ad
			if(vis[i][j]==0){
				vis[i][j]=1;
				dfs(i,j+1,sum+1);
				vis[i][j]=0;
			} 
			if(j==3) c=0;
		}
	}
	
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		flag=0;
		memset(vis,0,sizeof(vis));
		ans = 0;
		cin >> n;
		dfs(0,0,0);
		cout << ans << endl;
	}
}
