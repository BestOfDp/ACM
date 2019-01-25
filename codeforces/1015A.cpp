#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n;
	int m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		for(int j=x;j<=y;j++){
			a[j]=1;
		} 
	}
	vector<int>v;
	for(int i=1;i<=m;i++){
		if(a[i]==0) v.push_back(i);
	}
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
} 
