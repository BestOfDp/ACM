#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int ans[105][105];
int main()
{
	int n,m,h;
	cin >>n >> m >> h;
	for(int i=0;i<m;i++){
		cin >> a[i];
	}	
	for(int i=0;i<n;i++){
		cin >> b[i];
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> ans[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i][j]==1){
				ans[i][j] = min(a[j],b[i]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
} 
