#include<bits/stdc++.h>
using namespace std;
const int maxn=201;
int n,m;
int mp[maxn][maxn];

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j) mp[i][j]=0;
					else mp[i][j]=1e9;
				}
			}
			for(int i=0;i<m;i++)
			{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				mp[x][y]=min(z,mp[x][y]);
				mp[y][x]=min(z,mp[y][x]);
			}
			
			int s,t;
			scanf("%d%d",&s,&t);
			for(int k=0;k<n;k++)
			{
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
					}
				}
			}
			if(mp[s][t]==1e9) printf("-1\n");
			else printf("%d\n",mp[s][t]);
	}	
} 
