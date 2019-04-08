#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
int main(){
	int n,m;
	cin >> n >> m;
	int num1  = 0; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
			if(a[i][j]==1){
				num1++;
			}
		}
	}
	int num2 = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> b[i][j];
			if(a[i][j]==1){
				num2++;
			}
		}
	}
	if(num1%2 != num2%2){
		cout << "No" << endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		int c1 = 0;
		int c2 = 0;
		for(int j=0;j<m;j++){
			if(a[i][j]==1) c1++;
			if(b[i][j]==1) c2++;
		} 
		if(c1%2 != c2%2){
			cout << "No" << endl;
			return 0;
		} 
	}
	
	for(int i=0;i<m;i++){
		int c1 = 0;
		int c2 = 0;
		for(int j=0;j<n;j++){
			if(a[j][i]==1) c1++;
			if(b[j][i]==1) c2++;
		} 
		if(c1%2 != c2%2){
			cout << "No" << endl;
			return 0;
		} 
	}
	cout << "Yes" << endl;
	
	
	
} 
