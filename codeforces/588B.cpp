#include<bits/stdc++.h>
using namespace std;

int main()
{
	__int64 n;
	cin >> n;
	for(__int64 i=2;i<=1000000;i++)
	{
		while(n%(i*i)==0) n/=i;
	}
	cout << n << endl;
}
