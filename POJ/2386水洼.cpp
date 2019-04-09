#include<iostream>
#include<string>
using namespace std;
int n,m;
string ma[105];
int vis[105][105];
int ans;
int dir[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1}};

int judge(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0) return 1;
	return 0;
}
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<8;i++){
		int tempx = x+dir[i][0];
		int tempy = y + dir[i][1];
		if(judge(tempx,tempy)==1 && ma[tempx][tempy]=='W'){
			dfs(tempx,tempy);
		}
	}
}
int main()
{
	ans=0;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> ma[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==0 && ma[i][j]=='W') {
				dfs(i,j);
				ans++;	
			}
		}
	}
	cout << ans << endl;
}
