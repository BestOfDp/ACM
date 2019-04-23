#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l,r;
	for(int i=1;i<s.size();i++){
		if(s[i-1] > s[i]){
			cout << "YES" << endl;
			cout << i << " " << i+1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
