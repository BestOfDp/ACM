#include<bits/stdc++.h>
using namespace std;
int num[100005];
int main()
{
	int n,m;
	cin >> n >> m;
	int index=0;
	int current=0;
	for(int i=0;i<m;i++){
		long long a;
		cin >> a;
		if(num[a]==0){
			current++;
		}
		num[a]++;
		if(current==n){
			cout << 1;
			current=0;
			for(int j=1;j<=n;j++){
				if(num[j]>1){
					current++;
				}
				num[j]--;
			}
		}
		else cout << 0 ;
	}
	
} 
