#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<long long>v;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	long long ans = 0;
	int min1=1e9+7;
	for(int i=v.size()-1;i>=0;i--){
		if(v[i]<min1){
			min1 = v[i];
		}else{
			min1--;
		}
		ans += max(min1,0);
	}
	cout << ans << endl;
 } 
