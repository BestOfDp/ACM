#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int fun(char s[])
{
	int i;
	int len=strlen(s);
	int count=0;
	for(i=0;i<len/2;i++)
	{
		if(s[i]==s[len-i-1])
		{
			count++;
		}
	}
	if(count==len/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char s[1001];
	int a[1001];
	int i;
	int b[1001];
	
	while(scanf("%s",&s)!=EOF)
	{
		int sum=0;
		int count=0;
		if(fun(s)==1)
		{
			printf("1\n");
			printf("%s\n",s);
			continue;
		}
		int len=strlen(s);
		for(i=0;i<len;i++)
		{
			a[i]=s[i]-'0';
		}
		for(i=0;i<len;i++)
		{
			sum+=a[i]*pow(10,len-1-i);
		}
		b[0]=sum;
		
		int index=1;
		while(fun(s)!=1)
		{
			int sum=0;
			int len=strlen(s);
			for(i=0;i<len;i++)
			{
				a[i]=s[i]-'0';
			}
			for(i=0;i<len;i++)
			{
				sum+=a[i]*pow(10,len-1-i);
			}
			for(i=len-1;i>=0;i--)
			{
				sum+=a[i]*pow(10,i);
			}
			b[index++]=sum;
			itoa(sum,s,10);
			count++;
		}
		printf("%d\n",count);
		for(i=0;i<count+1;i++)
		{
			if(i==0) printf("%d",b[i]);
			else printf("--->%d",b[i]);
		}
		printf("\n");
	}
}


