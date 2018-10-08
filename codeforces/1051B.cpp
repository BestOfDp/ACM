#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y;	
	cin >> x >> y;
	cout << "YES" << endl;
	for(long long i = x;i<y;i+=2){
		cout << i << " " << i+1 << endl;
	}
} 
