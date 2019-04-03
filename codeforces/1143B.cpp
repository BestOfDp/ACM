#include<bits/stdc++.h>
using namespace std;
int n;
int f(int n){
	if(n<10) return max(1,n);
	return max((n%10) * f(n/10),9 * f(n/10-1));
}
int main()
{
	cin >> n;
	cout << f(n) << endl;
}
