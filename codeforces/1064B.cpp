#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int t;
	cin >> n ;
	for(int i=0;i<n;i++){
		cin >> t;
		cout << (1<< __builtin_popcount(t)) << endl;
	}	
} 
