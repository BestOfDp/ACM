#include<bits/stdc++.h>
using namespace std;
map<char,int>m1;
map<char,int>m2;
int main()
{
	string ans = "NO";
	string need;
	cin >> need;
	string ff;
	m1[need[0]] = 1;
	m2[need[1]] = 1;
	for(int i=0;i<5;i++){
		cin >> ff;
		if(m1[ff[0]] == 1) ans="YES";
		if(m2[ff[1]] == 1) ans="YES";
	} 
	cout << ans << endl;
}
