#include<stdio.h>
#include<memory.h>

int main ()
{
	int n,n1;
	int j,i;
	int t;
	char a[1000][1000];
	int hours,minutes,seconds;
	int hours1,minutes1,seconds1;
	scanf("%d",&t);
	while(t--)
	{
			scanf("%d",&n1);
			int max=0;
			int index=0;
			int index1=0;
			int min=86400;
			for(j=0;j<n1;j++)
			{
				scanf("%s",&a[j]);
				scanf("%d:%d:%d",&hours,&minutes,&seconds);
				if((hours*3600+minutes*60+seconds)<min )
				{
					min=hours*3600+minutes*60+seconds;
					index=j;
				}
				scanf("%d:%d:%d",&hours1,&minutes1,&seconds1);
				if((hours1*60*60+minutes1*60+seconds1)>max )
				{
					max=hours1*3600+minutes1*60+seconds1;
					index1=j;
				}
			}
			printf("%s %s\n",a[index],a[index1]);
	}
}
