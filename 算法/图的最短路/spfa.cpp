#include<bits/stdc++.h>
#define INF 99999999
using namespace std;
int main()
{
	int n,m;
	int u[8],v[8],w[8]; // u ----> v 的 distance  w
	int first[6],next[8]; // first比n大1    !!!! next比m大1
	int dis[6],vis[8]; //book记录哪些顶点已经在队列中 
	
	int  que[101]={0},head=1,tail=1; //定义一个队列 
	
	scanf("%d%d",&n,&m); // 顶点数 边数
	
	for(int i=1;i<=n;i++) dis[i]=INF;  //初始化dis数组 
	dis[1]=0;
	
	for(int i=1;i<=n;i++) vis[i]=0; //初始化 表示一开始都不在队列中 
	
	for(int i=1;i<=n;i++) first[i]=-1; //表示 1到n 一开始暂时没有边
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		//下面两句是建立邻接表的关键 
		next[i]=first[u[i]];
		first[u[i]]=i;
	} 
	
	//1号顶点入队
	que[tail]=1;
	tail++;
	vis[1]=1; //标记1号顶点已经入队
	
	int k;
	while(head < tail ) // 队列不为空的时候循环
	{
		k=first[que[head]]; //需要处理的顶点 其实就是 队列的头
		while(k!=-1)//扫描当前顶点所有的边 
		{
			if(dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]]+w[k];
			
				if(vis[v[k]]==0)
				{
					que[tail]=v[k];
					tail++;
					vis[v[k]]=1;
				}
			}
			k=next[k];
		}
		//出队
		vis[que[head]]=0;
		head++; 
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
	 
}
