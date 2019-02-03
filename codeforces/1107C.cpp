#include<bits/stdc++.h>
using namespace std;
map<int,vector<long long> >m;
vector<long long >v; 
int main()
{
	int n,k;
	cin >> n >> k;
	long long a;
	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	string s;
	cin >> s;
	vector<int> ans;
	ans.push_back(0);
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]) ans.push_back(i); 
	}
	ans.push_back(n);
	for(int i=0;i<ans.size()-1;i++){
		vector<long long>temp;
		temp.clear();
		for(int j=ans[i];j<ans[i+1];j++){
			temp.push_back(v[j]);
		}
		sort(temp.begin(),temp.end());
		long long sum=0;
		int index=0;
		for(int j=temp.size()-1;j>=0;j--){
			sum+=temp[j];
			index++;
			if(index==k) break;
		}
		int number = s[ans[i]];
		m[number].push_back(sum);
	}
	long long total=0;
	map<int,vector<long long> >::iterator iter;
	for(iter=m.begin();iter!=m.end();iter++){
		for(int i=0;i<iter->second.size();i++){
			total += iter->second[i];
		}
	}
	cout << total << endl;
} 
