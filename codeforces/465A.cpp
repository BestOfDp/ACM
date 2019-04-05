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

int n,m;
//int inborad(int x,int y)
//{
//	if(x>=0 && x<n && y>=0 && y<m) return 1;
//	return 0;
//}

vector<int>ans[1001];
int main()
{
	int a[1005];
	cin >> n;
	int index=0;
	int temp=1;
	int t;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(t==1)
		{
			a[index++]=t;
			temp=0;
		}
		else if(temp==0)
		{
			a[index++]=t;
		}
	}
	int k;
	if(index==0)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i=index-1;i>=0;i--)
	{
		k=i;
		if(a[i]==1)
		{
			k=i;
			break;
		}
	}
//	for(int i=0;i<k;i++) cout << a[i] << " ";
	//cout << k << endl;
	int cnt=0;
	int flag=0;
	for(int i=0;i<=k;i++)
	{
		if(a[i]==1)
		{
			cnt++;
			flag=1;
		}
		else if(a[i]==0 && flag==1)
		{
			cnt++;
			flag=0;
		}
	}
	cout << cnt << endl;
}
