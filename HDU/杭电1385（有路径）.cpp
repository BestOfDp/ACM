#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
int mat[1001][1001];
int tax[1001];
int path[1001][1001];
int n,m;
int main()
{
	int a;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a);
				if(a==-1) mat[i][j]=INF;
				else mat[i][j]=a;
				path[i][j]=j;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tax[i]);
		}
		
		int spos,epos;
		while(scanf("%d %d",&spos,&epos)!=EOF)
		{
			if(spos==-1 && epos==-1) break;
			if(spos==epos)
			{
				printf("From %d to %d :\n",spos,epos);
				printf("Path: %d\n",spos);
				printf("Total cost : 0\n");
				printf("\n");
				continue;
			}
			
			int index=0;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(mat[i][j] > mat[i][k]+mat[k][j]+tax[k])
						{
							mat[i][j]=mat[i][k]+mat[k][j]+tax[k];
							path[i][j]=path[i][k];
						//	index++;
						}
						else if(mat[i][j]==mat[i][k]+mat[k][j]+tax[k])
						{
							if(path[i][j]>path[i][k])
							{
								path[i][j]=path[i][k];
							//	index++;	
							}
						}
					}
				}
			}
			printf("From %d to %d :\n",spos,epos);
			printf("Path: %d",spos);
			int b,c;
			b=spos;
			c=epos;
			while(b!=c)
			{
				b=path[b][c];
				printf("-->%d",b);
			}
			printf("\n");
			printf("Total cost : %d\n\n",mat[spos][epos]);
		}
	}
}
