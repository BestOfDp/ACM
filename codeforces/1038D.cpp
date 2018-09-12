#include<bits/stdc++.h>
using namespace std;
long long a[500005];

int main()
{
	int n;
	cin >> n;
	int t;
	for(int i=0;i<n;i++) cin >> a[i];
	if(n==1){
		cout << a[0] << endl;
	}else if(n==2){
		sort(a,a+n);
		cout << a[1]-a[0] << endl;
	}else{
		long long ans=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]<0){
			 a[i]=-a[i];
			 cnt++;	
			}
			ans+=a[i];
		}
		sort(a,a+n);
		if(cnt==0 || cnt==n) ans-=2*a[0];
		cout << ans << endl;
	}
}
