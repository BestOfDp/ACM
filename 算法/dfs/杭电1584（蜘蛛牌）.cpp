#include<stdio.h>
#include<math.h> 
#include<string.h>
int num[15];
int count,index,min;
int vis[20];
void dfs(int a,int y)
{
	if(y>=min) return ;
	if(a==10)
	{
		min=y;
		return ;
	}
	for(int i=1;i<10;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			for(int j=i+1;j<=10;j++)
			{
				if(vis[j]==0)
				{
					dfs(a+1,y+abs(num[i]-num[j]));
					break;	
				}	
			} 
			vis[i]=0;
		}
	}
	
}
int main()
{
	int t;
	int qa;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		count=0;
		for(int i=1;i<=10;i++)
		{
			scanf("%d",&qa);
			num[qa]=i;
		}	
		min=2000000;
		dfs(1,0);
		printf("%d\n",min);
	}	
} 
