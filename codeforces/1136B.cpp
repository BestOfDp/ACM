#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	cout << 3*n + min(n-m,m-1) << endl;
} 
