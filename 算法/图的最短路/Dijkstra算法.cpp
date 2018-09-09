#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#define INF 99999999
using namespace std;
int main()
{
	int n,m;
	int mat[10][10];
	int dis[10];
	int vis[10];
	int a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) mat[i][j]=0;
			else mat[i][j]=INF;
		}
	}
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mat[a][b]=c;
	} 
	
	for(int i=1;i<=n;i++) dis[i]=mat[1][i];
	for(int i=1;i<n;i++)
	{
		//找到没有走过并且距离最小的点
		int min1=INF;
		int pos=-1;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0 && dis[j]<min1)
			{
				min1=dis[j];
				pos=j;	
			}	
		} 
		if(pos==-1) break;
		vis[pos]=1;
		for(int j=1;j<=n;j++)
		{
			if(mat[pos][j]<INF)
			{
				dis[j]=min(dis[j],dis[pos]+mat[pos][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
}
//6 9
//1 2 1
//1 3 12 
//2 3 9
//2 4 3
//3 5 5
//4 3 4
//4 5 13
//4 6 15
//5 6 4
