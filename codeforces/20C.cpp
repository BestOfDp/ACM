#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,vector<pair<int,int> > >g;
long long node[100005],dis[100005];
#define inf 1000000000000000000
priority_queue<int>s;
void printfpath(int n)
{
	if(n!=1) printfpath(node[n]);
	cout << n << " ";
}
int main()
{
	cin >> n >> m;
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	s.push(1);
	for(int i=1;i<=n;i++)
	{
		dis[i]=inf;
		node[i]=i;
	}
	dis[1]=0;
	while(!s.empty())
	{
		u = s.top();
		s.pop();
		for(int i=0;i<g[u].size();i++)
		{
			v=g[u][i].first;
			w=g[u][i].second;
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u]+w;
				s.push(v);
				node[v]=u;
			}
		}
	}
	if(dis[n]==inf) cout << -1 << endl;
	else
	{
		printfpath(n);
		cout << endl;
	}
} 
