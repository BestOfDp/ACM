#include<bits/stdc++.h>
using namespace std; 
const double eps = 1.0e-6; //¸¡µã 
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
	__int64 x,y,l;
}po[100005];

int cmp1(node a,node b)
{
	return a.l < b.l;
}

int cmp2(int a,int b)
{
	return a>b;
}

int gcd(int a,int b)
{
	int c=a;
	int d=b;
	int mod=a%b;
	while(b)
	{
		mod = a%b;
		a=b;
		b=mod;
	}
	return a;
}

//int inborad(int x,int y)
//{
//	if(x>=0 && x<n && y>=0 && y<m) return 1;
//	return 0;
//}
vector<int>ans;

int main()
{
	__int64 n,m,t;
	cin >> n >> m;
	int vis[200005];
	
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(t<200005) vis[t]=1;
	} 
	for(int i=1;m-i>=0;i++)
	{
		if(vis[i]==1) continue;
		m-=i;
		ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++) cout << ans[i]  << " ";
}
