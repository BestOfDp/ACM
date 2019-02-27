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

//void sovle(int l,int r)
//{
//	int temp=0;
//	for(int i=l+1;i<r;i++)
//	{
//		if(temp==0 && s[i]!='_')
//		{
//			num2++;
//			temp=1;
//		}
//		if(temp==1 && s[i]=='_')
//		{
//			temp=0;
//		}
//	}
//}
__int64 a[300005];
int vis[300005];
int main()
{
	int n;
	cin >> n;
	int min1=1;
	int max1=n;
	__int64 cnt=0;
	for(int i=0;i<n;i++) 
	{
		cin >> a[i];	
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		cnt+=(abs(a[i]-(i+1)));
	}
	cout << cnt << endl;
}
