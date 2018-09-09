#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t,i,j;
	int num=1;
	char a[10001];
	char b[10001];
	int c[10001];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		memset(c,0,sizeof(c));
		scanf("%s %s",&a,&b);
		int lena=strlen(a);
		int lenb=strlen(b);
		int max=lena;
		int indexa=lena-1;
		int indexb=lenb-1;
		if(lenb>max)
		{
			max=lenb;
		}
		for(i=max;i>0;i--)
		{
			int sum;
			if(max==lena)
			{
				if(indexb>=0)
				{	
				 	sum=((a[indexa--]-'0')+(b[indexb--]-'0'));	
				}
				else
				{
					sum=(a[indexa--]-'0');
				}	
			}
			else
			{
				if(indexa>=0)
				{
				 	sum=((a[indexa--]-'0')+(b[indexb--]-'0'));	
				}
				else
				{
				sum=(b[indexb--]-'0');
				}
			}
			c[i]+=sum;
			while(c[i]>=10)
			{
				c[i-1]+=1;
				c[i]=c[i]%10;
			}
		}
		printf("Case %d:\n",num++);
		printf("%s + %s = ",a,b);
		for(i=0;i<=max;i++)
		{
			if(i==0 && c[i]==0)
			{
				continue;
			}
			printf("%d",c[i]);	
		}
		printf("\n");
		if(j!=t-1)
		{
			printf("\n");
		}
	}
}

