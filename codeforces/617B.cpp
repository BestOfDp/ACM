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

vector<int>ans[200005];
int main()
{
	int n;
	cin >> n;
	int a[105];
	int flag=0;
	int t;
	int index=0;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(t==1)
		{
			a[index++]=t;
			flag=1;
		}
		if(flag==0) continue;
		if(t==0 && flag==1) a[index++]=t;
	}
	if(index==0) cout << 0 << endl;
	else
	{
		__int64 sum=1;
		flag=0;
		int cnt=0;
		for(int i=1;i<index;i++)
		{
			if(a[i]==0) cnt++;
			else if(a[i]==1)
			{
				sum*=(cnt+1);
				cnt=0;
			}
		}
		cout << sum << endl;
	}
}
