#include<bits/stdc++.h>
using namespace std;
int a[9006][600];
int main()
{
	a[1][0]=1;
	a[2][0]=1;
	a[3][0]=1;
	a[4][0]=1;
	for(int i=5;i<9006;i++)
	{
		for(int j=0;j<600;j++)
		{
			a[i][j]=a[i][j]+ a[i-1][j]+a[i-2][j]+a[i-3][j]+a[i-4][j];
			a[i][j+1]=a[i][j+1]+a[i][j]/10000;
			a[i][j]%=10000;
		}
	}
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1 || n==2 || n==3 || n==4)
		{
			printf("1\n");
			continue;
		}
		
		int start;
		for(int i=599;i>=0;i--)
		{
		//	printf("%d\n",a[n][i]);
			if(a[n][i]!=0)
			{
				printf("%d",a[n][i]);
				start=--i;
			//	printf("dad");
				break;
			}
		}
	//	printf("\n%d\n",start);
		for(int i=start;i>=0;i--)
		{
	//		printf("dada");
			printf("%04d",a[n][i]);
		}
		printf("\n");
	}
} 
