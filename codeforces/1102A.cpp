#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	if(n%2==0){
		cout << n/2 % 2 << endl;
	}else{
		if(n/2 % 2==1){
			cout << 0 << endl;
		}else cout << 1 << endl;
	} 
	
 } 
