#include<bits/stdc++.h>
using namespace std;

int l[1005],r[1005];
int num[1005];
int main()
{
	int n;
	cin >> n;	
	for(int i=0;i<n;i++){
		cin >> l[i];
	}
	vector<int>v;
	for(int i=0;i<n;i++){
		cin >> r[i];
		num[i]=r[i]+l[i];
		v.push_back(n-num[i]);
	}
	for(int i=0;i<n;i++){
		int left=0;
		int right=0;
		for(int j=0;j<i;j++){
			if(v[j] > v[i]) left++;
		}
		if(left!=l[i]) return puts("NO");
		
		for(int j=i+1;j<n;j++){
			if(v[j] > v[i]) right++;
		}
		if(right!=r[i]) return puts("NO");
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++){
		cout << v[i] << " ";
	}
	cout << endl;
} 
