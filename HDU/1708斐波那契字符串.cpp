#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
struct node
{
	__int64 a[27];
}zm[55];

int main()
{
	char b[27];
	int t,i,l,j,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(zm,0,sizeof(zm));
		for(i=0;i<2;i++)
		{
			getchar();
			scanf("%s",b);
			l=strlen(b);
			for(j=0;j<l;j++)
			{
				zm[i].a[b[j]-97]++;	
			}	
		}
		scanf("%d",&k);
		for(i=2;i<=k;i++)
		{
			for(j=0;j<27;j++)
			{
				zm[i].a[j]=zm[i-1].a[j]+zm[i-2].a[j];
			} 
		}
		for (i = 0 ; i < 26 ;i ++)
		{
			printf("%c:%I64d\n",i+97,zm[k].a[i]);
		}
		puts("");
	}
 }  
