#include<bits/stdc++.h>
using namespace std;
int main()
{
	 int t;
	 long long a,b,c,r;
	 cin >> t;
	 for(int i=0;i<t;i++){
	 	cin >> r >> a >> b >> c;
	 	cout << r/c + (r/c)/a*b << endl;
	 }
} 
