#include<bits/stdc++.h>
using namespace std; 
const double eps = 1.0e-6; //¸¡µã 
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int cnt;
string s[105];
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
	int n;
	cin >> n;
	string dir;
	__int64 dis;
	__int64 y=0;
	int flag=1;
	for(int i=0;i<n;i++)
	{
		cin >> dis >> dir;
		if(y==0 && dir!="South") flag=0;
		if(y==20000 && dir!="North") flag=0;
		if(dir=="North") y-=dis;
		if(dir=="South") y+=dis;
		if(y<0 || y>20000) flag=0;
	}
	if(y!=0) cout << "NO" << endl;
	else
	{
		if(flag==1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
