#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int v,k;
		cin >> v >> k;
		if(k==0){
			a[v]=a[i+1]=1;
		}
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0) {
			cout << i << " ";
			flag=0;	
		}
	}
	if(flag){
		cout << -1 << endl;
	}
} 
