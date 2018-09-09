#include<stdio.h>
#include<math.h> 
int main()
{
	int t;
	int n;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=log10((double)i);
		}
		printf("%d\n",(int)sum+1);
	}	
} 
