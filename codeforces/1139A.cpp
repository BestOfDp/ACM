#include<bits/stdc++.h>
using namespace std;
int number[65005];
int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')%2==0) {
			number[i+1]=number[i]+1;
		}else{
			number[i+1]=number[i];
		}
	}
	for(int i=1;i<=s.size();i++){
//		cout << number[i] << endl;
		ans += (number[s.size()] - number[i]);
		if((s[i-1]-'0')%2==0) ans++;
	}
	cout << ans << endl;
 } 
