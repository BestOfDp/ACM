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
 

//bool is[10000005];
//__int64 pri[100005];
//void prime()  
//{  
//    memset(is,0,sizeof(is));  
//    int cot=0;  
//    for(__int64 i=2;i<=10000000;i++)  
//    {  
//        if(is[i]==false)  
//        {
//            {  
//                if(cot>=100000)  
//                    break;  
//                pri[++cot]=i;  
//                for(__int64 j=i;j<=10000000;j=j+i)  
//                {  
//                    is[j]=true;  
//                }  
//            }  
//        }
//    }  
//} 

//vector<int> ans[100005];

int main()
{
	__int64 dp[200][2];
	int n,m,k;
	memset(dp,0,sizeof(dp));
	cin >> n >> m >>k;
	dp[0][0]=1;
	dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i-j>=0) 
			{
				dp[i][0]+=dp[i-j][0];
				dp[i][0]%=1000000007;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k-1;j++)
		{
			if(i-j>=0) 
			{
				dp[i][1]+=dp[i-j][1];
				dp[i][1]%=1000000007;
			}
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		cout << dp[i][0] << " ";
//		cout << dp[i][1] <<endl;
//	}
	
	cout << (dp[n][0] - dp[n][1] + 1000000007 ) %1000000007  <<endl;
}
