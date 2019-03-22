#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	if(m%n==0){
		int div = m/n;
		if(div==1){
			cout << 0 << endl;
		}else{
			int ans = 0;
			while(div>=2){
				if(div%3==0){
					ans++;
					div/=3;
				}else if(div%2==0){
					ans++;
					div/=2;
				}else{
					cout << -1 << endl;
					return 0;
				}
			}
			cout << ans << endl;
		}
	}else{
		cout << -1 << endl;
	}
}
