#include<bits/stdc++.h>
using namespace std;
int a[500];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans =0 ;
		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			if(temp>6000) ans++;
		}	
		cout << ans << endl;
	}
} 
