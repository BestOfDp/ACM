#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int a1=0;
	int a2=0;
	int b1=0;
	int b2=0;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		if(temp%2==0){
			a1++;
		}else a2++;
	}	
	for(int i=0;i<m;i++){
		int temp;
		cin >> temp;
		if(temp%2==0){
			b1++;
		}else b2++;
	}	
	cout << min(a1,b2)+min(a2,b1) << endl;
} 
