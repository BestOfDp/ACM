#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
	int n,m,k;
	int a,b;
	cin >> n >> m >> k;
	v.push_back(0);
	for(int i=0;i<n;i++){
		cin >> a >> b;
		v.push_back(a);
		v.push_back(a+b);
	}
	v.push_back(m);
	int sum=0;
	for(int i=0;i<v.size();i+=2){
		sum+= (v[i+1]-v[i])/k;
	}
	cout << sum << endl;
} 
