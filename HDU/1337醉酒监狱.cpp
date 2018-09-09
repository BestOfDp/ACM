#include<stdio.h>
#define MAXSIZE 100
int main()
{
	int i,i1,j,k,n,n1,p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int num[MAXSIZE]={0};
		{
			scanf("%d",&n1);
			for(j=1;j<=n1;j++)
			{
				for(k=1;k<=n1;k++)
				{
					if(k%j==0)
					{
						num[k-1]++;
					}
				}
			}
			int count=0;
			for(i1=0;i1<n1;i1++)
			{
				if(num[i1] % 2 ==1)
				{
					count++;
				}
			}
			printf("%d\n",count);
		}
	}
 }
