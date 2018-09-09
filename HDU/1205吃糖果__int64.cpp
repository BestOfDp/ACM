#include<stdio.h>
int main()
{
	int n,i,n1;
	int j;
	__int64 sum,temp,max;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			max=0;
			sum=0;
			scanf("%d",&n1);
			for(j=0;j<n1;j++)
			{
				scanf("%d",&temp);
				if(temp>=max)
				{
					max=temp;
				}
				sum+=temp;
			}
			if(sum-max+1>=max)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
}

