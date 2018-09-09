#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,ans,x;
	
	while(scanf("%d",&n))
	{
		if(n == 0)
		{
			break;
		}
		ans = 0;
		while(n --)
		{
			scanf("%d",&x);
			ans ^= x;//“ÏªÚ 
		}
		printf("%d\n",ans);
	}
	return 0;
}
