#include<bits/stdc++.h>
using namespace std; 
const double eps = 1.0e-6; //¸¡µã 
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int cnt;

struct node
{
	int x,y;
};

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
//	if(x>=0 && x<n && y>=0 && y<n) return 1;
//	return 0;
//}


int main()
{
	int n;
	cin >> n;
	int a[105];
	for(int i=1;i<=n;i++) cin >> a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) cnt++;
		else if(a[i]==1)
		{
			if(a[i+1]==1)	a[i+1]=0;
		//	else if(a[i+1]==2)	cnt++;
			else if(a[i+1]==3)	a[i+1]=2;	
		}
		else if(a[i]==2)
		{
			if(a[i+1]==2)	a[i+1]=0;
		//	else if(a[i+1]==1)	cnt++;
			else if(a[i+1]==3)	a[i+1]=1;
		}
	}
	//for(int i=1;i<=n;i++) cout << a[i] << " "; 
	cout << cnt << endl;
}


