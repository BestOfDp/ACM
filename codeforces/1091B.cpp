#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<int,int>,int>m;
vector<pair<int,int> >v1;
vector<pair<int,int> >v2;
int main()
{
	cin >> n;
	int x,y;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		v1.push_back(make_pair(x,y));
	}
	for(int i=0;i<n;i++){
		cin >> x >> y;
		v2.push_back(make_pair(x,y));
	}
	for(int i=0;i<v1.size();i++){
		x=v1[i].first;
		y=v1[i].second; 
		for(int j=0;j<v2.size();j++){
			m[make_pair(x+v2[j].first,y+v2[j].second)]++;
		} 
	}
	map<pair<int,int>,int>::iterator iter;
	for(iter=m.begin();iter!=m.end();iter++){
		if(iter->second==n){
			cout << iter->first.first << " " << iter->first.second << endl;
			return 0;
		}
	}
} 
