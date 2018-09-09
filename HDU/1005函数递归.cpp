#include<stdio.h>
int main()
{
	int a,b,n,j;
	int arr[100];
	arr[1]=1;
	arr[2]=1;
	while(scanf("%d %d %d",&a,&b,&n) !=EOF)
	{
		if(a==0&&b==0&&n==0)
		{
			break;
		}
		for(j=3;j<=49;j++)
		{
			arr[j]=(a*arr[j-1] + b*arr[j-2]) % 7;
		}
		printf("%d\n",arr[n%49]);
	}
}

