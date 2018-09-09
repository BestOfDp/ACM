#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	char a[10000];
	int b[10000];
	int i;
	while(scanf("%s",a) != EOF)
	{
		int t=0;
		int flag=0;
		memset(b,0,sizeof(b));//±ÿ–Î”– 
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]!='5')
			{
				b[t]=b[t]*10+(a[i]-'0');
				flag=1;
			}
			else if(flag)
			{
				t++;
				flag=0;
			}
			if(a[i]!='5' && a[i+1]=='\0')
			{
				t++;
			} 
		}
		sort(b,b+t);
		for(i=0;i<t;i++)
		{
			if(i==0)
			{
				printf("%d",b[i]);
			}
			else
			{
				printf(" %d",b[i]);
			}
		}
		printf("\n");
	}
 } 
