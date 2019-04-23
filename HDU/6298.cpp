#include<bits/stdc++.h>
using namespace std;
int todo(int sum){
	int maxn = -1;
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			int total = i+j;
			int need = sum - total;
			if(need <=0) continue;
			if(sum%i==0 && sum%j==0 && sum%need==0){
				maxn = max(maxn,i*j*need);
			}
		}
	}	
	cout << sum << " " << maxn << endl; 
}
int main()
{
	for(int i=1;i<=100;i++) todo(i);
} 
