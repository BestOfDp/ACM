#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[55][200];
	int b[55][27]={0};
	int i,t,j,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(b,0,sizeof(b));
		for(i=0;i<2;i++)
		{
			getchar();
			scanf("%s",s[i]);
		}
		for(i=0;i<2;i++)
		{
			for(j=0;j<strlen(s[i]);j++)
			{
				b[i][s[i][j]-97]++;	
			}	
		}
		scanf("%d",&k);
		for(i=2;i<=k;i++)
		{
			for(j=0;j<26;j++)
			{
				b[i][j]=b[i-1][j]+b[i-2][j];	
			}
		}
		for(j=0;j<26;j++)
		{
			printf("%c:%d\n",j+97,b[k][j]);
		}
		printf("\n");
	}
}
