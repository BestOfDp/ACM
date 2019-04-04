#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
set<int>s;
vector<int>asc;
vector<int>desc;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		m[temp]++;
		s.insert(temp);
	}
	set<int>::iterator iter;
	for(iter=s.begin();iter!=s.end();iter++){
		int number = *iter;
		if(m[number]>2){
			cout << "NO" << endl;
			return 0;
		}
		desc.push_back(number);
		if(m[number]==2){
			asc.push_back(number);
		}
	}
	cout << "YES" << endl;
	cout << asc.size() << endl;
	for(int i=0;i<asc.size();i++){
		cout << asc[i] << " ";
	}
	cout << endl;
	sort(desc.begin(),desc.end());
	cout << desc.size() << endl;
	for(int i=desc.size()-1;i>=0;i--){
		cout << desc[i] << " ";
	}
	cout << endl;
	
} 
