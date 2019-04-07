#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<long long>dis;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	long long sum=0;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		sum+=v[i];
	}
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
		int index;
		cin >> index;
		cout << sum- v[n-index]   << endl;
	}
} 
