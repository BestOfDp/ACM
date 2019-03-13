#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int a[101];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(m==0 && n!=1)
		{
			printf("-1 -1\n");
			continue;
		}
		if(9*n<m)
		{
			printf("-1 -1\n");
			continue;
		}
		if(n==1)
		{
			printf("%d %d\n",m,m);
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(i==0) a[i]=1;
			else if(i==n-1) a[i]=m-1;
			else a[i]=0;
		}
		int k=n-1;
		while(a[k]>9)
		{
			a[k-1]+=a[k]-9;
			a[k]=9;
			k--;
			if(k==0) break;
		}
		if(a[0]>=10) 
		{
			printf("-1 ");	
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				printf("%d",a[i]);
			}
			printf(" ");
		}
		
		int c=m;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			if(c<9)
			{
				a[i]=c;
				c=0;
				break;
			}
			a[i]=9;
			c-=9;
		}
		if(c)
		{
			printf("-1\n");
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				printf("%d",a[i]);
			}
		}
		printf("\n");
	} 
}
