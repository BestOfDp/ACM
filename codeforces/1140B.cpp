#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int index_left = -1;
		for(int i=0;i<n;i++){
			if(s[i]=='<'){
				index_left = i;
			}
		}
		int index_right = -1;
		for(int i=0;i<n;i++){
			if(s[i]=='>'){
				index_right = i;
				break;
			}
		}
		if(index_left!=-1 && index_right!=-1) {
			cout << min(index_right,n-index_left-1) << endl; 
		}else cout << 0 << endl;
	}
} 
