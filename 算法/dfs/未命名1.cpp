#include<bits/stdc++.h>
using namespace std;
int n,m;
int Map[15][15];

struct node
{
	int x,y,steps;
};

node pre[15][15];
int visit[15][15];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
node spos,epos;

int inborad(int x,int y)
{
	if(x>=0 && x<n &&y>=0 &&y<m) return 1;
	else return 0;
}
int main()
{
	printf("请输入地图大小:\n");
	scanf("%d%d",&n,&m);
	printf("请输入地图:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&Map[i][j]);
		}
	}
	printf("请输入起点位置:\n");
	scanf("%d%d",&spos.x,&spos.y);
	printf("请输入终点位置:\n");
	scanf("%d%d",&epos.x,&epos.y);
	spos.steps=0;
	queue<node> Q;
	Q.push(spos);
	node temp,temp1;
	int flag=0;
	visit[spos.x][spos.y]=1;
	
	while(!Q.empty())
	{
		temp=Q.front();
		Q.pop();
		if(temp.x==epos.x && temp.y==epos.y)
		{
			printf("shortest dist:%d\n",temp.steps);
			node route[300];
			int cnt=0;
			int xx=temp.x,yy=temp.y;
			temp1.x=xx;
			temp1.y=yy;
			while(xx!=spos.x || yy!=spos.y)
			{
				route[cnt++]=temp1;
				temp1=pre[temp1.x][temp1.y];
				xx=temp1.x;
				yy=temp1.y;
			}
			printf("(%d,%d)",spos.x,spos.y);
			for(int i=cnt-1;i>=0;i--)
			{
				printf("(%d,%d)",route[i].x,route[i].y);
			}
			flag=1;
			break;
		}
			temp1.steps=temp.steps+1;
			for(int i=0;i<4;i++)
			{
				temp1.x=temp.x+dir[i][0];
				temp1.y=temp.y+dir[i][1];
				if(inborad(temp1.x,temp1.y) && !visit[temp1.x][temp1.y] && Map[temp1.x][temp1.y])
				{
					pre[temp1.x][temp1.y]=temp;
					visit[temp1.x][temp1.y]=1;
					Q.push(temp1);
				}
			}
	}
		if(!flag)
		{
			printf("No solution!\n");
		}
} 
