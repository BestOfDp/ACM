#include<bits/stdc++.h>
using namespace std;
int a[10054];
int main(){
	int n;
	cin >> n;
	int b; 
	for(int i=0;i<n;i++){
		cin >> b;
		a[b]++; 
	}
	int number = 0;
	int maxn= 0;
	for(int i=1;i<=1000;i++){
		if(a[i]>0){
			number++;
			maxn = max(maxn,a[i]);
		}
		
	}
	cout << maxn << " " << number << endl;
}  
