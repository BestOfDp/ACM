#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int mod = n%3;
	switch(mod){
		case 0:{
			cout << 1 <<" " <<  1 <<" " << n-2 << endl;
			break;
		};
		case 1:{
			cout << 1 <<" " <<  2 <<" " << n-3 << endl;
			break;
		};
		case 2:{
			cout << 2 <<" " <<  2 <<" " << n-4 << endl;
			break;
		};
	}
}
