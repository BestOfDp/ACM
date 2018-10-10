#include<bits/stdc++.h>
using namespace std;
int main()
{
	int flag=0;
	int n;
	cin >> n;
	int t;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(t) flag=1;
	}
	if(flag) cout << "HARD" << endl;
	else cout << "EASY" << endl;
 } 
