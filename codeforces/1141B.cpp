#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int n;
	cin >> n;
	int index=-1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==0) index=i;
	}
	// 
	vector<int> v; 
	if(index!=-1){
		for(int i=index;i<n;i++){
			v.push_back(a[i]);
		}
		for(int i=0;i<index;i++){
			v.push_back(a[i]);
		}
	}else{
		cout << n << endl;
		return 0;
	}
	int ans=0;
	int current=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==0){
			current=0;
		}else{
			if(current==0){
				current=1;
			}
			if(v[i-1]==1){
				current++;
			}
		}
		ans = max(ans,current);
	}
	cout << ans << endl;
}
