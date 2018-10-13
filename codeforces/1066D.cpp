#include<bits/stdc++.h>
using namespace std;
int a[2000005];
vector<long long>v[200005];
int main()
{
	int n,m,t;
	cin >> n >> m >> t;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int index=0;
	long long sum=0;
	for(int i=n-1;i>=0;i--){
		if(sum+a[i]<=t){
			sum+=a[i];
			v[index].push_back(a[i]);
		}else{
			if(index==m-1) break; 
			v[++index].push_back(a[i]);
			sum=a[i];
		}
	}
	int ans=0;
	for(int i=0;i<=index;i++){
		ans+=v[i].size();
	}
	cout << ans << endl;
}

