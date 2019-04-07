#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int main()
{
	long long n,m;
	cin >> n >> m;
	int ans=1;
	for(int i=1;i<=n;i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
		sort(v.begin(),v.end());
		long long sum=0;
		for(int j=i;j>0;j-=2){
			sum += v[j-1];
		}
		if(m >= sum){
			ans = i;
		}
	}
	cout << ans << endl;
}
