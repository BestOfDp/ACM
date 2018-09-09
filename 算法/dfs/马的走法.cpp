#include<bits/stdc++.h>
using namespace std;
int vis[100][100]={0};
int n,m;
int tot=0;
int  inboard(int x,int y)
{
	if((x>=0 && x<n && y>=0 && y<m))
	{
		return 1;
	}
	else return 0;
}
void dfs(int x,int y,int cur)
{
	if(inboard(x,y) && !vis[x][y])
	{
		cur++;
		vis[x][y]=cur;
		if(cur==n*m)
		{
			tot++;
			printf("Case#%d:\n",tot);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					printf("%d ",vis[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			vis[x][y]=0;
		}
		else
		{
			dfs(x-1,y-2,cur);
			dfs(x-1,y+2,cur);
			dfs(x-2,y-1,cur);
			dfs(x-2,y+1,cur);
			dfs(x+1,y-2,cur);
			dfs(x+1,y+2,cur);
			dfs(x+2,y-1,cur);
			dfs(x+2,y+1,cur);
			vis[x][y]=0;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	dfs(0,0,0);
} 
