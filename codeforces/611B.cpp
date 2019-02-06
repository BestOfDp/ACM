#include<bits/stdc++.h> 
using namespace std;

__int64 n,m; 
int cnt;
void dfs(__int64 a,int t)
{
	//cout << a << endl;
	if(a>m) return;
	if(a>=n && a<=m && t==1) cnt++;
	if(t==0)
	{
		dfs(a*2,1);
	}
	dfs(2*a+1,t);
}
int main()
{
	cin >> n >> m;
	dfs(1,0);
	cout << cnt << endl;
}

