#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	long long sum=0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n/2;i++){
		sum += (a[i]+a[n-1-i]) * (a[i]+a[n-1-i]);
	} 
	cout << sum << endl;
}
