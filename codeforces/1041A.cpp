#include<bits/stdc++.h>
using namespace std;
int a[2000];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	int ans=0;
	for(int i=1;i<n;i++){
		ans+=a[i]-a[i-1];
	}
	cout << ans-n+1 << endl;
}
