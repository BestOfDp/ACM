#include<stdio.h>
__int64 a[200005];
int main()
{
	int n;
	int i,j;
	int temp;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		int sum=0;
		for(i=0;i<n;i++)
		{
			temp=0;
			int max=-1;
			for(j=i;j<n;j++)
			{
				if(a[j]>max) max=a[j]; 
				if(a[j]==temp) temp++;
				if(temp==max) temp++;
				sum+=temp;
			}
		}
		printf("%d\n",sum);
	}
}
