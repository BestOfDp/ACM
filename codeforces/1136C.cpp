#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1[505][505];
int a2[505][505];
int judge(int x,int y){
	if(x>=0 && x<=n && y>=0 && y<=m) return 1;
	return 0;
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a1[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a2[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		vector<int> v1;
		vector<int> v2;
		v1.clear();
		v2.clear();
		
		int j=0;
		while(1){
			if(judge(i-j,j)==0){
				break;
			}
			v1.push_back(a1[i-j][j]);
			v2.push_back(a2[i-j][j]);
			j++;
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		for(int j=0;j<v1.size();j++){
			if(v1[j]!=v2[j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	
	for(int i=1;i<m;i++){
		vector<int> v1;
		vector<int> v2;
		v1.clear();
		v2.clear();
		
		int j=0;
		while(1){
			if(judge(n-1-j,i+j)==0){
				break;
			}
			v1.push_back(a1[n-1-j][i+j]);
			v2.push_back(a2[n-1-j][i+j]);
			j++;
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		for(int j=0;j<v1.size();j++){
			if(v1[j]!=v2[j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" <<endl;
	
	
}
