#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
int mat[10][10]; 
int n,m; 
int main()
{
	int a,b,c;
	//          顶点个数  m条边 
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) mat[i][j]=0;
			else mat[i][j]=INF;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		mat[a][b]=c;	
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(mat[i][j] > mat[i][k] + mat[k][j])
				{
					mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%10d",mat[i][j]);
		}
		printf("\n");
	}
}
