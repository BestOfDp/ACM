#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j;
	char c[3],c1[3];
	while(scanf("%s",c) != EOF)
	{
		for(j=0;j<strlen(c);j++)
		{
			for(i=0;i<strlen(c)-1;i++)
			{
				if(c[i]>c[i+1])
				{
					char p;
					p=c[i];
					c[i]=c[i+1];
					c[i+1]=p;
				}
			}
		}
		printf("%c %c %c\n",c[0],c[1],c[2]);
	}
}
