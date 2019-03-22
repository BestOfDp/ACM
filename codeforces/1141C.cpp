#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int vis[200005];
int main(){
//	n n-2 n-1 
//	n n+1 n+2 n+3 n+4
//	n n-1 n+1 n+3 
	int n;
	cin >> n;
	a[0]=0;
	int t;
	long long mmin = 1e9;
	long long mmax = 0;
	for(int i=1;i<n;i++){
		cin >> t;
		a[i] = a[i-1] + t;
//		cout << a[i] << endl;
		mmin = min(a[i],mmin);
		mmax = max(a[i],mmax); 
	}
	int index;
	if(mmin<=0){
		index = 1 - mmin;
	} else if(mmin==1){
		index = 1;
	}else{
		cout << -1 <<endl;
		return 0;
	}
	vector<int>v;
	for(int i=0;i<n;i++){
//		cout << index <<" " << a[i] << endl;
		int number = index + a[i];
		if(number>n){
			cout << -1 <<endl;
			return 0;
		}
		if(vis[number]==0){
			vis[number]=1;
		}else{
			cout << -1 << endl;
			return 0;
		}
		v.push_back(number);
	}
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
}
