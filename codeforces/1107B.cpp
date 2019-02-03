#include<bits/stdc++.h>
using namespace std;
int findS(long long t){
	if(t<10) return t;
	int sum=0;
	while(t){
		sum+= t%10;
		t/=10;
	}
	return findS(sum);
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		long long a,b;
		cin >> a >> b;
		cout << (a-1)*9 + b << endl;
	}
} 
