#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,k,a1,b1,a,b;
	scanf("%d",&n);
	if(n<=0)
	{
		exit(-1);
	}
	for(i=0;i<n;i++)
	{
		int count=0;
		scanf("%d %d",&a,&b);
		if(a<=1 || b>=10000)
		{
			exit(-1);
		}
		if(a<=b)
		{
			a1=a;
			b1=b;
		}
		else
		{
			a1=b;
			b1=a;
		}
		for(j=a1;j<=b1;j++)
		{
			int sum=0;
			for(k=1;k<j;k++)
			{
				if(j % k == 0)
				{
					sum+=k;
				}
			}
			if(sum == j)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
