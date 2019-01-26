#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int main()
{
	int n;
	cin >> n;
	int t;
	int current = 1;
	cin >> t;
	for(int i=1;i<n;i++){
		cin >> t;
		if(t!=1){
			current = t;
		}else{
			ans.push_back(current);
			current=1;
		}
	}
	ans.push_back(current);
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	
 } 
