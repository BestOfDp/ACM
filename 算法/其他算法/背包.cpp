01����--------------------------------------------------------
n*v
for(int i=1;i<=n;i++)
{
	for(int j=weight[i];j<=V;j++)
	{
		dp[i][j]=max(dp[i][j],dp[i-1][j-weight[i]]+value[i]);	
	}	
} 
�� dp[1][V]; 

�����Ż�-------------------------------------------------------
2*v
int now=1;pre=0;
for(int i=1;i<=n;i++)
{
	for(int j=weight[i];j<=V;j++)
	{
		dp[now][j]=max(dp[now][j],dp[pre][j-weight[i]]+value[i]);	
	}	
	swap(now,pre);
} 
*************************************
for(int i=1;i<=n;i++)
{
	for(int j=V;j>=weight[i];j--)
	{
		dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
	}
}

�� dp[V]; 

��ȫ���� 
-------------------------------------------------------
for(int i=1;i<=n;i++)
{
	for(int j=weight[i];j<=V;j++)
	{
		dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
	}
}

�� dp[V]


���ر���---------------------------------------------------
for(int i;i<=n;i++)
{
	for(int j=0;j<=num[i];j++)
	{
		for(int k=V;k>=j*weight[i];k--)
		{
			dp[i][k]=max(dp[i][k],dp[i-1][k-j*weight[i]]+j*value[i]);
		}
	}
}
