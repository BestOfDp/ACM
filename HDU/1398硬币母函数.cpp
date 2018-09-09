#include<stdio.h>
int main()
{
	int n,i,j,k;
	int c1[1001],c2[1001];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(i=0;i<=n;i++)
		{
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i<=17;i++) //****************************** 
		{
			for(j=0;j<=n;j++)
			{
				for(k=0;k+j<=n;k+=i*i) //**************************************** 
				{
					c2[j+k]+=c1[j];
				}
			}
			for(j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[n]);
	}
}
