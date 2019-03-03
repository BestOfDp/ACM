#include<bits/stdc++.h>
using namespace std;
int num[100005]; 
int main()
{
	int n;
	cin >> n;
	int maxn=0;
	int a;
	for(int i=0;i<n;i++){
		cin >> a;
		maxn = max(a,maxn);
		num[a]++;
	}
	cout << maxn << " ";
	for(int i=1;i<=sqrt(maxn);i++){
		if(maxn%i==0){
			num[i]--;
			if(maxn/i!=i){
				num[maxn/i]--;
			}
		}
	}
	for(int i=10000;;i--){
		if(num[i]==1){
			cout << i << endl;
			return 0;
		}
	} 
 } 
