#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	long long x,y,a,b;
	cin >> x >> y >> a >> b;
	long long div = gcd(a,b);
	a/=div;
	b/=div;
	cout << min(x/a,y/b) << endl;
}
