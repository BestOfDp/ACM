#include<stdio.h>
#include<math.h>
int main()
{
	int n1,n,i;
	int a;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			break;
		}
		a=n;
		for(i=2;i<=n;i++)
		{
			a=a*n%9;
		}
		if(a==0)
		{
			printf("9\n");
		}
		else
		{
			printf("%d\n",a);
		}
	}
}
