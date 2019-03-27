#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ve[100005];
long long ans;
long long mod = 1e9 + 7;
int vis[100005];
long long number;
void dfs(int a){
	vis[a]=1;
	number++;
	for(int i=0;i<ve[a].size();i++){
		if(vis[ve[a][i]]==0){
			dfs(ve[a][i]);
		}
	}
}
int main()
{
	cin >> n >> m;
	ans = 1;
	for(int i=0;i<m;i++){
		ans = ans * n % mod;
	}
	int u,v,x;
	for(int i=0;i<n-1;i++){
		cin >> u >> v >> x;
		if(x==0){
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			number = 0;
			dfs(i);
			int dis = 1;
			for(int j=0;j<m;j++){
				dis = dis * number % mod;
			}
			ans = (ans-dis + mod)%mod;
		}
	}
	cout << (ans+mod)%mod << endl;
} 
