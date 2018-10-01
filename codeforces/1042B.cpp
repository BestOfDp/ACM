#include<bits/stdc++.h>
using namespace std;
long long INF = 1e9;
map<string,long long>m;
int main()
{
	int n;
	long long p;
	string a;
	m["A"] = INF;        
	m["B"] = INF;        
	m["C"] = INF;        
	m["AB"] = INF;        
	m["AC"] = INF;        
	m["BC"] = INF;        
	m["ABC"] = INF;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> p >> a;
		sort(a.begin(),a.end());
		m[a] = min(m[a],p);	 
	}
	long long ans = INF;        
	ans = min(m["A"] + m["B"] + m["C"], ans);        
	ans = min(m["A"] + m["BC"], ans);        
	ans = min(m["B"] + m["AC"], ans);        
	ans = min(m["C"] + m["AB"], ans);        
	ans = min(m["AB"] + m["AC"], ans);        
	ans = min(m["BC"] + m["AC"], ans);        
	ans = min(m["AB"] + m["BC"], ans);        
	ans = min(m["ABC"], ans);        
	if(ans < 0 || ans >= INF) ans = -1;        
	cout << ans << endl; 
} 
