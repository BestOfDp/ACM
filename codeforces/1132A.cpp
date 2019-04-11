#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==d){
		if(c==0 || a>=1){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}else cout << 0 << endl;
}
