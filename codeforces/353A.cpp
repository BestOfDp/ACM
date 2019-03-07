#include<bits/stdc++.h>
using namespace std; 
const double eps = 1.0e-6; //¸¡µã 
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
	__int64 x,y,l;
}po[100005];

struct node1
{
	__int64 x,y,l;
}po1[100005];

int cmp1(node a,node b)
{
	return a.x < b.x;
}

int cmp3(node1 a,node1 b)
{
	return a.x > b.x;
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
vector<int>ans[1001];
int main()
{
	int n;
	cin >> n;
	int a,b;
	int cnt1=0;
	int cnt2=0;
	int sum1=0;
	int sum2=0;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		sum1+=a;
		sum2+=b;
		if(a%2!=b%2) cnt1++;
	}
	if(sum1%2==0 && sum2%2==0)
	{
		cout << "0" << endl;
	}
	else
	{
		if(cnt1%2==0 && cnt1 > 0) cout << 1 << endl;
		else cout << -1 << endl;
	}
}
