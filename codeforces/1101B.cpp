#include<bits/stdc++.h>
using namespace std;
string s;
string ss;
int main()
{
	ss = ""; 
	cin >> ss;
	int ans=0;
	vector<int>v1;
	vector<int>v2;
	for(int i=0;i<ss.size();i++){
		if(ss[i]=='[') v1.push_back(i);
		if(ss[i]==']') v2.push_back(i);
	}
	if(v1.size()==0){
		cout << -1 << endl;
		return 0;
	}
	if(v2.size()==0){
		cout << -1 << endl;
		return 0;
	}
	vector<int>v;
	for(int i=v1[0];i<v2[v2.size()-1];i++){
		if(ss[i]==':') v.push_back(i);
	}
	if(v.size()<=1){
		cout << -1 << endl;
		return 0;
	}
	for(int i=v[0];i<=v[v.size()-1];i++){
		if(ss[i]=='|'){
			ans++;
		}
	}
	cout << ans + 4 << endl;
}
