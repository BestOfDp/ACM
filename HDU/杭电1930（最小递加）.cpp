#include<bits/stdc++.h>
using namespace std;
int pass(int a,int b,int c,int d)
{
	if(a==b && a==c && a==d && b==c &&b==d &&c==d) return 1;
	else return 0;
}

int main()
{
	int t;
	int a1,a2,a3,a4;
	scanf("%d",&t);
	int a[4];
	int add[4];
	int b[100];
	int aa;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<4;i++)
		{
			scanf("%d",&a[i]); 
			add[i]=100000/a[i]*a[i];
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&aa);
			a4=aa%100;
			a3=aa/100%100;
			a2=aa/10000%100;
			a1=aa/1000000%100;
			int min1=max(max(a1,a2),max(a3,a4));
			while(1)
			{
				if(a1<min1)
				{
					a1+=a[0];
				}
				if(a2<min1)
				{
					a2+=a[1];
				}		
				if(a3<min1)
				{
					a3+=a[2];
				}		
				if(a4<min1)
				{
					a4+=a[3];
				}
				min1=max(max(a1,a2),max(a3,a4));	
				if(pass(a1,a2,a3,a4)==1)
				{
					b[i]=a1;	
					break;
				}
			}
		}
		int ac[1001];
		int index=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0,k=10000;j<3;j++)
			{
				ac[index++]=b[i]/k%100;
				k/=100;
			}
		}
		int acc;
		for(int i=index-1;i>=0;i--)
		{
			if(ac[i]!=27)
			{
				acc=i;
				break;
			}
		}
		for(int i=0;i<=acc;i++)
		{
			if(ac[i]!=27) printf("%c",ac[i]-1+'A');
			else printf(" ");
		}
		printf("\n");
	}
} 


