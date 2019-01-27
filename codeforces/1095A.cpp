#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int sum=0;
	int jump=1;
	for(int i=0;;i++){
		if(sum+jump > s.size()) break;
		cout << s[sum];
		sum+=jump++;
	}
 } 
