#include<bits/stdc++.h>
using namespace std;
const double eps = 1.0e-6; //¸¡µã
vector<int>mat[10005];
int pa;

int de;
void dfs(int x,int pre,int pp)
{ 
	if(pp>pa)
	{
		pa = pp;
		de = x;
	}
	for(int i=0;i<mat[x].size();i++)
	{
		if(mat[x][i]!=pre)
		{
			dfs(mat[x][i],x,pp+1);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin >> u >> v;
		mat[u].push_back(v);
		mat[v].push_back(u);
	} 
	
	for(int i=1;i<=n;i++)
	{
		if(mat[i].size()!=0)
		{
			dfs(i,-1,0);
			break;
		}
	}
//	cout << endl;
	pa=0;
	
	dfs(de,-1,0);
	dfs(de,-1,0);
	cout << pa << endl;
}
