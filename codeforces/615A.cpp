#include<bits/stdc++.h>
using namespace std;
int a[10054];
int main(){
	int n,m;
	cin >> n >> m;
	int sum=0;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		for(int j=0;j<k;j++){
			int temp;
			cin >> temp;
			if(a[temp]==0){
				a[temp]++;
				sum++;
			}
		}
	}
	if(sum==m) cout << "YES" << endl;
	else cout << "NO" << endl;
}  
