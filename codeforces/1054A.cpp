#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,t1,t2,t3;
	cin >> x >> y >> z>> t1>>t2>>t3;
	int star = 0;
	star = abs(x-y) * t1;
	int eve = 0;
	eve = 3*t3 +  (abs(z-x) + abs(x-y)) * t2;
	if(eve<=star) cout << "YES" << endl;
	else cout << "NO" << endl; 	
} 
