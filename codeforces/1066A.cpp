#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t;
	int a,b,c,d;
	while(t--){
		cin >>a>>b >>c >>d;
		cout << a/b - (d/b - (c-1)/b) << endl;
	}
}	
