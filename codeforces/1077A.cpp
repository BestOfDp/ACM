#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		long long a,b,c;
		cin >> a >> b >> c;
		long long ans = (a-b) *((c+1)/2);
		if(c%2==1){
			ans += b;
		}
		cout << ans << endl;
	}	
} 
