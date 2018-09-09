#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int a[1005];
int dp[1005];

int main()
{
	int n;
	int i, j;
	while (scanf("%d", &n) != EOF && n)
	{	
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		dp[1] = a[1];
		for (i = 2; i <= n; i++)
		{
			dp[i] = a[i];
			for (j = 1; j < i; j++)
				if (a[i] > a[j])
					dp[i] = max(dp[i], dp[j] + a[i]);
		}
		int ma=0;
		for (i = 1; i <= n; i++)
			if (dp[i] > ma)  ma = dp[i];
		printf("%d\n", ma);
	}
	return 0;
}
