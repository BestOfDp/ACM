#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	v.push_back(0);
	int n;
	cin >> n;
	int pre,temp;
	cin >>temp;
	int sum=0;
	sum++;
	pre = temp;
	for(int i=1;i<n;i++){
		cin >> temp;
		if(temp!=pre){
			pre = temp;
			v.push_back(sum);
			sum = 0;
			sum++;
			continue;
		}
		sum++;
	}
	v.push_back(sum);
	int ans=0;
	for(int i=1;i<v.size();i++){
		ans = max(min(v[i],v[i-1]) * 2,ans);
	}
	cout << ans << endl;
} 
