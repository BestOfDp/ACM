#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z;
	cin >> x >> y >> z;
	int a,b,c;
	cin >> a >> b >> c;
	int sum= a+b+c;
	string ans = "YES";
	if(a>=x){
		a-=x;
		if(a+b >= y){
			b = (a+b) - y;
			if(!((b+c) >= z)) ans="NO";
		}else ans="NO";
	}else ans = "NO";
	cout << ans << endl;
} 
