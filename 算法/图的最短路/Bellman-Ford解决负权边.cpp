#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
int dis[10];
int u[10],v[10],w[10];

int main()
{
	int n,m; //n ������� m ·���ĸ��� 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
	}
	dis[1]=0;
	
	for(int k=1;k<=n-1;k++)
	{
		for(int i=1;i<=m;i++)
		{
			if(dis[u[i]] + w[i] < dis[v[i]])
			{
				dis[v[i]]= dis[u[i]] + w[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
}
