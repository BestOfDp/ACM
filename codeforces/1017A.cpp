#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
int cmp(pair<int,int>a ,pair<int,int>b){
	if(a.first==b.first){
		return a.second < b.second;
	}
	else{
		return a.first > b.first;	
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin >> a>>b >> c >> d;
		v.push_back(make_pair(a+b+c+d,i));
	}
	sort(v.begin(),v.end(),cmp); 
	for(int i=1;;i++){
		if(v[i-1].second==0){
			cout << i << endl;
			return 0;
		}
	}
}
