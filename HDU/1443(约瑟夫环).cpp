#include<bits/stdc++.h>
using namespace std;
int isGood(int x, int k){
	int start = 0, n1 = k * 2;
	while (n1 > k){
		start = (start + x - 1) % n1;
		if (start < k)   return 0;
		else   
			n1--;
	}
	return 1;
}

int main()
{
	int j;
	int n;
	int a[15];
	for(int i=1;i<14;i++)
	{
		int flag=1;
		for(j=i;;j++)
		{
			if(isGood(j,i))
			{
				a[i]=j;
				break;
			}
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		printf("%d\n",a[n]);
	}
} 


