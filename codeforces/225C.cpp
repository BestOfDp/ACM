#include<bits/stdc++.h>
using namespace std;
string ma[1005];
int n,m,a,b;
int dp[1005][2];
int main(){
	cin >> n >> m >> a >> b;
	for(int i=0;i<n;i++){
		cin >> ma[i];
	}
	int number[1005];
	for(int i=0;i<m;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(ma[j][i]=='#') cnt++;
		}
		number[i] = cnt;
	}
	for(int i=1;i<=m;i++){
		dp[i][0]=1e9;
		dp[i][1]=1e9;
	}
	
	for(int i=0;i<m;i++){
		for(int j=a;j<=b;j++){
			if(i+j > m) break;
			int nu = 0;
			for(int k=i;k<i+j;k++){
				nu += number[k];
			}
			int sharp = nu;
			int dol = j * n  - nu;
			dp[i+j][0] = min(dp[i+j][0],sharp + dp[i][1]);
			dp[i+j][1] = min(dp[i+j][1],dol + dp[i][0]);
		}
	}
	cout << min(dp[m][0],dp[m][1]) << endl;
	
}  
