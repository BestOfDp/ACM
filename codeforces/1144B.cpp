#include<bits/stdc++.h>
using namespace std;
vector<int>a;
vector<int>b;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		if(temp&1){
			a.push_back(temp);
		}else b.push_back(temp);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int s1 = a.size();
	int s2 = b.size();
	if(abs(s1-s2)<=1){
		cout << 0 << endl;
		return 0;
	}
	if(s1 > s2){
		int ans = 0;
		for(int i=0;i<(s1-s2-1);i++){
			ans += a[i];
		}
		cout  << ans << endl;
	}else{
		int ans = 0;
		for(int i=0;i<(s2-s1-1);i++){
			ans += b[i];
		}
		cout  << ans << endl;
	}
}


