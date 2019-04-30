#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin >> n >> m >>k;
	int min1=1e9;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		min1 = min(min1,temp);
	}
	int max1=0;
	for(int i=0;i<m;i++){
		int temp;
		cin >> temp;
		max1 = max(max1,temp);
	}
	if(max1<min1) cout << k << endl;
	else
	cout << (max1-min1) * (k/min1) + k<< endl;
} 
