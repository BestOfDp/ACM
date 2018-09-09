#include<stdio.h>
int main()
{
	int a[5]={8,9,5,6,7};
	int i,j;
	int min=0;
	for(i=0;i<4;i++)
	{
		min=i;
		for(j=i;j<5;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min != i) //如果这个数本身就最小了 就不用交换了 
		{
			int t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
}
