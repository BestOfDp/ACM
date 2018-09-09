#include<bits/stdc++.h>
using namespace std;
int pre[105];
void print(int x)
{
	if(pre[x]!=0)
	{
		print(pre[x]);
	}
	printf("%d->",x);
}
int main()
{
	int t;
	int vis[105][105];
	int d[105];
	int w[105];
	int n,m,a,b;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&d[i]);
		d[n+1]=0;
		for(int i=1;i<=n+1;i++)
		{
			w[i]=0;
			pre[i]=0;
			for(int j=1;j<=n+1;j++)
			{
				vis[i][j]=0;
			}
		}
		
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			vis[a][b]=1;
		}
		
		for(int j=1;j<=n+1;j++)
		{
			int max1=0;
			int k=0;
			for(int i=1;i<j;i++)
			{
				if(vis[i][j]==1 && max1<=w[i])
				{
					max1=w[i];
					k=i;
				}
			}
			pre[j]=k;
			w[j]=max1+d[j];
		}
		printf("CASE %d#\npoints : %d\ncircuit : ",k,w[n+1]);
		print(pre[n+1]);
        printf("1\n"); 
        if(k!=t) printf("\n");        
	}	
} 
