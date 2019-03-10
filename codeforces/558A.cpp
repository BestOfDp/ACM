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
vector<int>ans;
int main()
{
	int  n,x,y;
	cin >> n;
	int a[105],b[105];
	int index1=0;
	int index2=0;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		if(x>0)
		{
			po[index1].x=x;
			po[index1++].y=y;
		} 
		else
		{
			po1[index2].x=x;
			po1[index2++].y=y;
		}
	}
	sort(po,po+index1,cmp1);
	sort(po1,po1+index2,cmp3);
	int sum=0;
	int num1=0;
	int num2=0;
	int flag=1;
	if(index1==0)
	{
		cout << po1[0].y;
		return 0;
	}
	else if(index2==0)
	{
		cout << po[0].y;
		return 0;
	}
	while(1)
	{
		if(index1>index2)
		{
			if(flag==1)
			{
				sum+=po[num1++].y;
				flag=0;	
			}
			else 
			{
				sum+=po1[num2++].y;
				flag=1;
			}
		}	
		else
		{
			if(flag==1)
			{
				sum+=po1[num2++].y;
				flag=0;	
			}
			else 
			{
				sum+=po[num1++].y;
				flag=1;
			}
		}	
		if(num2==index2)
		{
			sum+=po[num1++].y;
			break;	
		}
		if(num1==index1) 
		{
			sum+=po1[num2++].y;
			break;	
		}
	}
	cout << sum << endl; 
}
