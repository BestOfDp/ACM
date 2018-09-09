#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,j,n1,k,l,m,e;
	char color[1010][15];
	while(scanf("%d",&n) !=EOF && n)
	{
		int count[1010]={0};
		for(j=0;j<n;j++)
		{
			scanf("%s",color[j]);
		}
		for(k=0;k<n-1;k++)
		{
			for(l=k+1;l<n;l++)
			{
				if(strcmp(color[k],color[l]) == 0)
				{
					count[k]++;
				}
			}
		}
		int max=count[0];
		e=0;
		for(m=1;m<n;m++)
		{
			if(max<count[m])
			{
				e=m;	
			}
		}
		printf("%s\n",color[e]);
	}
 } 
