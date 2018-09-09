#include<stdio.h>
using namespace std;
int main()
{
	int n;
	int a;
	int b[101];
	int head=0;
	int tail=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(head==tail)
		{
			b[tail]=a;
			tail++;
		}
		else
		{
			while(b[tail-1]>a)
			{
				tail--;
			}
			b[tail++]=a;
		}
	}
	for(int i=head;i<tail;i++)
	{
		if(i==head)printf("%d",b[i]);
		else printf(" %d",b[i]);
	}
	printf("\n");
}

