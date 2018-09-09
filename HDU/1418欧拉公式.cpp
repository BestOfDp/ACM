#include<stdio.h>
int main()
{
	__int64 n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
		{
			break;
		}
		printf("%d\n",n-2+m); 
	}
}
 
