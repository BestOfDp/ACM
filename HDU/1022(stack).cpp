#include<stdio.h>
#include<stack>
using namespace std; 
int main()
{
	int n;
	int i;
	int c[3005];
	char a[1005],b[1005];
	while(scanf("%d",&n)!=EOF)
	{
		stack<char>q;
		scanf("%s%s",a,b);
		int k=0;
		int t=0;
		for(i=0;i<n;i++)
		{
			q.push(a[i]);
			c[t++]=1;
			while(!q.empty())
			{
				char x=q.top();
				if(x==b[k])
				{
					c[t++]=2;
					k++;
					q.pop();
				}
				else break;
			}
		}
		if(!q.empty())	printf("No.\nFINISH\n");
		else
		{
			printf("Yes.\n");
			for(i=0;i<t;i++)
			{
				if(c[i]==1) printf("in\n");
				else printf("out\n");
			}
			printf("FINISH\n");
		}
	}
}
