#include<stdio.h>
int main()
{
    int t;
    int n,i,j;
    int a;
    int start,end,temp;
    int index=1;
    scanf("%d",&t);
    while(t--)
    {
    	temp=start=end=1;
    	scanf("%d",&n);
    	int max=-100001;
    	int sum=0;
    	for(i=1;i<=n;i++)
    	{
    		scanf("%d",&a);
    		sum+=a;
    		if(sum>max)
    		{
    			max=sum;
    			start=temp;
    			end=i;
			}
			if(sum<0)
			{
				sum=0;
				temp=i+1;
			}
		}
		printf("Case %d:\n",index++);
		printf("%d %d %d\n",max,start,end);
		if(t!=0) printf("\n");
	}
 }


