#include<bits/stdc++.h>
using namespace std;
string ma[1005];
int n,m;
int my[1005][1005];
//ÅĞ¶ÏÄÜ·ñÓ¡ 
int judge(int x,int y){
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(i==x && j==y)continue;
			if(ma[i][j]=='.') return 0;
		}
	}
	return 1;
}
//Ó¡ 
void done(int x,int y){
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(i==x && j==y)continue;
			my[i][j]=1;
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> ma[i]; 
	}
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if(judge(i,j)){
				done(i,j);
			}
		} 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((my[i][j]==1 && ma[i][j]=='.') ||(my[i][j]==0 && ma[i][j]=='#')){
				cout  << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
} 
