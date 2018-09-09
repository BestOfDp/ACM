#include<stdio.h>
#include<string.h>
int main()
{
	char c;
	while(1)
	{	
		int s=0;
		while(scanf("%c",&c) && c!='\n')
		{
			s+=c-'0';
		}
		if(!s)return 0;
		else if(s%9==0)puts("9");
		else printf("%d\n",s%9);
	}
	return 0;
} 
