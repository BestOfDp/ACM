#include<iostream>
#include<set>
#include<vector>
using namespace std;
set<int>s;
vector<int>v;
int ex[11005];
int getIndexByPos(int pos){
	for(int i=0;i<v.size();i++){
		if(v[i]==pos) return i+1;
	}
	return 0;
}
int main()
{
	int r,n;
	while(cin>>r>>n){
		if(r==-1 && n==-1) break;
		s.clear();
		v.clear();
		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			ex[temp]=1;
			s.insert(temp);
		}
		int ans=0;
		set<int>::iterator iter;
		for(iter=s.begin();iter!=s.end();iter++){
			v.push_back(*iter);
		}
		int i=0;
		int num = v.size();
		while(i<num){
			int s = v[i++];
			while(i<num && v[i]<=s+r) i++;
			int p = v[i-1];
			while(i<num && v[i]<=p+r) i++;
			ans++;
		}
		cout << ans << endl;
	}
 } 
