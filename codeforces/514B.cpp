#include<bits/stdc++.h>
using namespace std; 
const double eps = 1.0e-6; //¸¡µã 
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
	__int64 x,y;
}po[100005];

int cmp1(node a,node b)
{
	if(a.x==b.x)
	{
		return a.y < b.y;
	}
	else return a.x < b.x;
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
vector<int>ans[200005];
int main()
{
	int n,x,y;
	int q,w;
	cin >> n >> x >> y;
	int index=0;
	int cnt=0;
	int temp1=0;
	int temp2=0;
	set<pair<int, int> >s; 
	for(int i=0;i<n;i++)
	{
		cin >> q >> w;
		if(q==x) s.insert(make_pair(0,1));
		else if(y==w) s.insert(make_pair(1,0));
		else
		{
			int num = gcd(x-q,y-w);
			s.insert(make_pair((x-q)/num,(y-w)/num));
		}
	}
	cout << s.size() << endl; 
}
