#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << min(min(b,a+1),c-1) * 3 << endl;
} 
