#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		if(n==1){
			cout << "NO" << endl;
			return 0; 
		}
		if(n==2){
			if(s[0]>=s[1]){
				cout << "NO" << endl;
			}else{
				cout << "YES" << endl;
				cout << 2 << endl;
				cout << s[0] << " " << s[1] << endl;
			}
		}
		else{
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << s[0] << " ";
			for(int i=1;i<n;i++){
				cout << s[i];
			}
			cout << endl;
		}
	}
 } 

