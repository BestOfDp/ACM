#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
map<int,int>m;
int main()
{
	int n;
	cin >> n; 
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		v2.push_back(x);
	}
	sort(v2.begin(),v2.end());
	int cnt=0;
	int number=0;
	for(int i=v2.size()-1;i>=0 ;i--){
		if(number==n) break;
		v1.insert(v1.begin()+cnt,v2[i]);
		cnt++;
		number++;
		if(number==n) break;
		i--;
		v1.insert(v1.begin()+cnt,v2[i]);
		number++;	
	}
	for(int i=0;i<v1.size();i++){
		cout << v1[i] << " ";
	} 
 } 
