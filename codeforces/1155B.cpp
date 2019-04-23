#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int e=0;
	for(int i=0;i<n-10;i++){
		if(s[i]=='8') e++;
	}
//	cout << e << " " << endl;
	int number = (n-11) / 2;
	if(number >= e){
		cout << "NO" << endl;
	}else cout << "YES" << endl;
}
