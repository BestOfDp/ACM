#include<bits/stdc++.h>
using namespace std;
const double eps = 1.0e-6; //¸¡µã
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
  __int64 x,y,l;
}po[200005];
//
////struct node1
////{
////  __int64 x,y,l;
////}po1[100005];
////
//int cmp0(int a,int b)
//{
//  return a>b;
//}
//
//int cmp1(node a,node b)
//{
//	if(a.x==b.x)
//	{
//		return a.y<b.y;	
//	}
//	return a.x < b.x;
//}
//
int cmp2(node a,node b)
{
	return a.x < b.x;
}

//int cmp3(node a,node b)
//{
//	return a.l < b.l;
//}

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


int main()
{
	int n,m,t,b;
	cin >> n >> m;
	int vis[10005];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<m;i++)
	{
		cin >>  t >> b;
		vis[t]=1;
		vis[b]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			ans=i;
			break;
		 } 
	}
	cout << n-1 <<endl;
	for(int i=1;i<=n;i++)
	{
		if(i!=ans)
		{
			cout << ans << " " << i << endl;
		}
	}
}
