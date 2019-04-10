#include<bits/stdc++.h>
using namespace std;
long long a[805];
int b[805];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		for(int i=0;i<n;i++) scanf("%lld",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		long long ans=0;
		for(int i=0;i<n;i++){
			ans += a[i] * b[n-i-1];
		}
		cout << ans << endl;
	}
}
