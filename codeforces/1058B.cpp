#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d;
	int t;
	cin >> n >> d;
	cin >> t;
	int x,y;
	for(int i=0;i<t;i++){
		cin >> x >> y;
		if(x+y-d<0||x+y-2*n+d>0||x-y-d>0||x-y+d<0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
} 
