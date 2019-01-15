#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			v.push_back(1LL*i);
			if(n/i != i) v.push_back(1LL* (n/i));
		} 
	}	
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		int number = n/v[i];
		cout << number + v[i]*(number-1)*number/2 << " "; 
	} 
} 
