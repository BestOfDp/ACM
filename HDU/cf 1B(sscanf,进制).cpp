#include <bits/stdc++.h>
using namespace std;
void convert(const int & c)
{
	if(c)
	{
		convert((c-1)/26);
		putchar((c-1)%26+65);
	}
}
int main()
{
	int n;
	char s[1001];
	char ans[1005];
	char s2[101];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%s",s);
		if(sscanf(s,"R%dC%d",&a,&b)==2)
		{
			convert(b);
			printf("%d\n",a);
		}
		else
		{
			sscanf(s,"%[A-Z]%d",s2,&a);
			printf("R%dC",a);
			int b=0;
			for(int k=1,j=strlen(s2)-1;j>=0;j--)
			{
				b+=(k*(s2[j]-'A'+1));
				k*=26;
			}
			printf("%d\n",b);
		}
	}
}
