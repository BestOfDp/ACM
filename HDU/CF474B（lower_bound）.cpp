#include<bits/stdc++.h>
using namespace std;	
int a[100011];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		a[i]+=a[i-1];
	}
	scanf("%d",&m);
	int t;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&t);
		int num = lower_bound(a,a+n,t)-a;
		printf("%d\n",num+1);
	}
} 

