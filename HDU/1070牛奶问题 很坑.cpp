#include<stdio.h>
int main()
{
	int n1,n;
	int i,j,b,day;
	double value;
	int p[1000],v[1000];
	char a[1000][1000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			float max=9999999;
			int b=0;
			scanf("%d",&n1);
			for(j=0;j<n1;j++)
			{
				scanf("%s %d %d",a[j],&p[j],&v[j]);
				if(v[j]<200)
				{
					continue;
				}
				else
				{
					day = v[j]/200;
					if(day>5)
					{
						day=5;
					}
					if(p[j]/day<=max)
					{
						if(p[j]/day<max)
						{
							max=p[j]/day;
							b=j;
						}
						else if(p[j]/day==max)
						{
							if(v[j]>v[b])
							{
								b=j;
							}
						}
					}
				}
			}
			printf("%s\n",a[b]);
		}
	}
}
