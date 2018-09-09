#include<bits/stdc++.h>
using namespace std;
int mat[1005][1005];
int vis[1005][1005];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,t;
int inborad(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m) return 1;
    else return 0;
}
struct node
{
    int x,y;
    int dir,count;
};

node spos,epos;

void bfs()
{
	queue<node>Q;
	int flag=1;
	node temp,temp1;
	temp.x=spos.x;
	temp.y=spos.y;
	temp.dir=-1;
	temp.count=0;
	Q.push(spos);
    while(!Q.empty())
    {
    	temp=Q.front();
    	Q.pop();
    	vis[temp.x][temp.y]=1;
        if(temp.x==epos.x && temp.y==epos.y)
        {
        	printf("YES\n");
            flag=0;
            break;
        }
        else
        {
	        for(int j=0;j<4;j++)
	        {
	            temp1.x=temp.x+dir[j][0];
	            temp1.y=temp.y+dir[j][1];
	            temp1.dir=j;
	            temp1.count=temp.count;
	            if(inborad(temp1.x,temp1.y)==0) continue;
	        	if(!(mat[temp1.x][temp1.y]==0 || (temp1.x==epos.x && temp1.y==epos.y))) continue;
	            if(temp1.dir!=temp.dir && temp.dir!=-1) temp1.count++;
	            if(temp1.count>2) continue;
	            if(temp.count < vis[temp1.x][temp1.y])
	        	{
	            	vis[temp1.x][temp1.y]=temp1.count;
	           		Q.push(temp1);
				}
	        }
    	}
    }
    if(flag)	printf("NO\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 &&m==0) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        scanf("%d",&t);
        queue<node>Q;
        node temp,temp1;
        for(int i=0;i<t;i++)
        {
            memset(vis,10000,sizeof(vis));
            scanf("%d%d%d%d",&spos.x,&spos.y,&epos.x,&epos.y);
            spos.dir=-1;
            spos.count=0;
            if(mat[spos.x][spos.y]!=mat[epos.x][epos.y] || mat[spos.x][spos.y]==0 || mat[epos.x][epos.y==0 ])
            {
            	printf("NO\n");
			}
			else if(spos.x==epos.x && spos.y==epos.y)
			{
				printf("NO\n");
			}
			else
			{
        		bfs(); 
            }
        }
    }
}

