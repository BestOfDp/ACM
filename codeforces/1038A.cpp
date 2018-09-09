#include<bits/stdc++.h>
using namespace std;
int v[27];
int main()
{
	string s;
	int n,k;
	cin >> n >> k >> s;
	int min1 = 1e9;
	for(int i=0;i<s.size();i++){
		v[s[i]-'A'] ++;
	}
	for(int i=0;i<k;i++){
		if(v[i] < min1) min1 = v[i];
	}
	cout << min1*k << endl;
}
