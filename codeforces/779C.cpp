#include<bits/stdc++.h>
using namespace std;
const double eps = 1.0e-6; //¸¡µã
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
  __int64 x,y,l;
}po[200005];

//struct node1
//{
//  __int64 x,y,l;
//}po1[100005];
//
int cmp0(int a,int b)
{
  return a>b;
}

int cmp1(node a,node b)
{
	if(a.x==b.x)
	{
		return a.y<b.y;	
	}
  	return a.x < b.x;
}

int cmp2(node a,node b)
{
	
  	return a.x < b.x;
}

int cmp3(node a,node b)
{
	return a.l < b.l;
}

//int gcd(int a,int b)
//{
//  int c=a;
//  int d=b;
//  int mod=a%b;
//  while(b)
//  {
//      mod = a%b;
//      a=b;
//      b=mod;
//  }
//  return a;
//}
 
//int inborad(int x,int y)
//{
//  if(x>=0 && x<n && y>=0 && y<m) return 1;
//  return 0;
//}

bool is[10000005];
__int64 pri[100005];
void prime()  
{  
    memset(is,0,sizeof(is));  
    int cot=0;  
    for(__int64 i=2;i<=10000000;i++)  
    {  
        if(is[i]==false)  
        {
            {  
                if(cot>=100000)  
                    break;  
                pri[++cot]=i;  
                for(__int64 j=i;j<=10000000;j=j+i)  
                {  
                    is[j]=true;  
                }  
            }  
        }
    }  
}  

vector<int> ans[100005];
int main()
{
	int n,m;
	int cnt=0;
	cin >> n >>m;
	for(int i=0;i<n;i++)
	{
		cin >> po[i].x;
	}
	for(int i=0;i<n;i++)
	{
		cin >> po[i].y;
		po[i].l = po[i].x - po[i].y;
		if(po[i].l<0) cnt++;
	}
	sort(po,po+n,cmp3);
	__int64 sum=0;
//	cout << cnt << " " << m <<endl;
	if(cnt >= m )
	{
		for(int i=0;i<n;i++)
		{
			if(po[i].l <= 0 )
			{
				sum+=po[i].x;	
			}	
			else sum+=po[i].y;
		}	
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(m)
			{
				sum+=po[i].x;
				m--;
			}
			else sum+=po[i].y;
		}
	}
	cout << sum << endl;
}
