#include<bits/stdc++.h>
using namespace std;
set<int>s;
map<int,int>m;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		s.insert(temp);
		m[temp]++;
	}
	set<int>::iterator iter;
	int ans = 0;
	for(iter=s.begin();iter!=s.end();iter++){
		int number = *iter;
		int sum=0;
		for(int j=0;j<=5;j++){
			sum += m[j+number];	
		}
		ans = max(ans,sum);
	}
	cout<<ans << endl;
} 
