#include<stdio.h>
//��С������ = (a*b)/���Լ��;
//��ֹ�������ȡ  (a/���Լ��)*b; 
int main()
{
	int n,n1,count,n2,m,z;
	int num[10000];
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&n1);
		for(j=0;j<n1;j++)
		{
			scanf("%d",&num[j]);	
		}
		count=num[0];
		for(k=1;k<n1;k++)
		{
			m=count;
			n2=num[k];
			while(z=m%n2)
			{
				m=n2;
				n2=z;
			}
			count = count/n2*num[k];
		}
		printf("%d\n",count);
	}
 } 

 
