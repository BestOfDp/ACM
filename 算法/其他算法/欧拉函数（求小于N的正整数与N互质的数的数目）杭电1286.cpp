#include<bits/stdc++.h>
using namespace std;
int f[10000]={2};

//int Eular(int a)
//{
//	int index=0;
//	int b[10000];
//	for(int i=0;f[i]<a;i++)
//	{
//		if(a%f[i]==0)
//		{
//			b[index++]=f[i];
//		}
//	}
//	for(int i=0;i<index;i++)
//	{
//		a=(a-a/b[i]);
//	}
//	return a;
//}

int Eular(int n)
{
	int rea = n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			rea = rea-rea/i;
			do
			{
				n/=i;
			}while(n%i==0);
		}
	}
	if(n>1) rea=rea-rea/n;
	return rea;
}


int main()
{
	int n;
	int k=1;
	for(int i=3;i<32770;i++)
	{
		int q=1;
		for(int j=0;j<k;j++)
		{
			if(i%f[j]==0){
				q=0;
				break;
			}
		}
		if(q) f[k++]=i;
	}
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		printf("%d\n",Eular(a));
	}
}
