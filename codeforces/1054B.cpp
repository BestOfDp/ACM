#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int main()
{
	int n;
	cin >> n;
	int ans = -1;
	int t;
	int cur=0; 
	for(int i=0;i<n;i++){
		cin >> t;
		if(t>cur){
			cout << i + 1<< endl;
			return 0;
		}
		m[t]++;
		if(m[t]==1) cur++;
	}	
	cout << -1 << endl;
} 
