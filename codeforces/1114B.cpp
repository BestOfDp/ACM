#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int b[200005];
map<int,int>ma;
map<int,int>vis;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++) {
		cin>>a[i];	
		ma[a[i]]++;
		b[i]=a[i];
	}
	sort(b,b+n);
	ll sum=0;
	int number=m*k;
	int div = b[n-m*k];
	for(int i=0;i<m*k;i++){
		int a = b[n-1-i];
		if(vis[a]==0 && a!=div){
			number-= ma[b[n-1-i]];
			vis[a]=1;
		}
		sum += b[n-1-i];
	}
	ma[div] = number;
	cout << sum << endl; 
	int cn = 0;
	for(int i=0;i<n;i++){
		if(k==1) return 0;
		if(a[i]>=div){
			if(a[i]==div){
				if(ma[div]>0){
					cn++;
					ma[div]--;
				}
			} cn++;		
			if(cn==m){
				cout << i+1 << " ";
				cn=0;
				k--;
			}
		}
	}
	
} 
