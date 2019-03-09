#include<bits/stdc++.h>
using namespace std;
long long dp[200005][5];
long long number = 1e9+7;
int main(){
	int n,l,r;
	cin >> n >> l >> r;
	dp[1][0]= (r/3) - ((l-1)/3);
	dp[1][1]= ((r+1)/3) - (l/3);
	dp[1][2]= ((r+2)/3) - ((l+1)/3);
	for(int i=2;i<=n;i++){
		dp[i][0] = (dp[i-1][0]*dp[1][0] + dp[i-1][1]*dp[1][2] + dp[i-1][2]*dp[1][1]) % number;
		dp[i][1] = (dp[i-1][0]*dp[1][1] + dp[i-1][1]*dp[1][0] + dp[i-1][2]*dp[1][2] ) %number;
		dp[i][2] = (dp[i-1][0]*dp[1][2] + dp[i-1][1]*dp[1][1] + dp[i-1][2]*dp[1][0])%number;
	}
	cout << dp[n][0] % number << endl;
} 
