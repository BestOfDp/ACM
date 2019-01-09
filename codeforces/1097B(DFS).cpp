#include<bits/stdc++.h>
using namespace std;
int a[1004];
int n;
string ans;
void dfs(int index,int op,int sum){
	sum = (sum+360)%360;
	if(index==n){
		if(sum==0){
			ans="YES";
		}
		return;
	}
	if(op==0){
		dfs(index+1,0,sum+a[index]);
		dfs(index+1,-1,sum+a[index]);
	}else{
		dfs(index+1,0,sum-a[index]);
		dfs(index+1,-1,sum-a[index]);
	}
}
int main()
{
	ans="NO";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	dfs(0,0,0);
	cout << ans << endl;
 } 
