#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin  >> t;
	long long x,y,k;
	while(t--){
		cin >>  x >> y >> k;
		if(max(x,y) > k){
			cout << -1 << endl;
		}else{
			long long ans = k;
			if(abs(x-y)%2==1){
				ans--;
			}else{
				if((k-x)%2 == 1){
					ans-=2;
				}
			}
			cout << ans << endl;
		}
	}
} 
