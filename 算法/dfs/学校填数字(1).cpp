#include<stdio.h>
#include<algorithm>
using namespace std;
int a[3];
int b[3];
int mat[3][3];
int p[3][3];
int index;
int dfs(int i)
{
	if(i==3)
	{
		int flag=1;
		for(int i1=0;i1<3;i1++)
		{
			if(mat[0][i1]+mat[1][i1]+mat[2][i1] != a[i1])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
//			for(int i1=0;i1<3;i1++)
//			{
//				for(int j=0;j<3;j++)
//				{
//					if(j==0) printf("%d",mat[i1][j]);
//					else printf(" %d",mat[i1][j]);
//				}
//				printf("\n");
//			} 
		index++;
		}
		return 0;
	}
	else
	{
		for(int i1=1;i1<p[i][0];i1++)
		{
			for(int j=1;j<p[i][1];j++)
			{
				for(int k=1;k<p[i][2];k++)
				{
					if(i1+j+k==b[i])
					{
						mat[i][0]=i1;
						mat[i][1]=j;
						mat[i][2]=k;
						dfs(i+1);
					}
				}
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<3;i++)
		{
			scanf("%d",&a[i]);
		}		
		for(int i=0;i<3;i++)
		{
			scanf("%d",&b[i]);
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				p[i][j]=min(a[j],b[i]);	
//				printf("%d ",p[i][j]);
			}
		//	printf("\n");
		} 
		index=0;
		for(int i=1;i<p[0][0];i++)
		{
			for(int j=1;j<p[0][1];j++)
			{
				for(int k=1;k<p[0][2];k++)
				{
					//printf("%d %d %d\n",i,j,k); 
					if(i+j+k==b[0])
					{
						mat[0][0]=i;
						mat[0][1]=j;
						mat[0][2]=k;
						dfs(1);
					}
				}
			}
		}
		printf("%d\n",index);
	}		
}
//6 12 5
//4 5 6
//1 7 6
//
//11 24 17
//23 15 14
