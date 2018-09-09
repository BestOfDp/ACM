#include<stdio.h>
#include <algorithm>
using namespace std;
int a[999999];
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		j=(n+1)/2;
		sort(a,a+n);
		printf("%d\n",a[j]);
	}
 } 
