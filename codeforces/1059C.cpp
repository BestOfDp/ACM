#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans=1;
	while(n>3){
		for(int i=0;i<n/2+n%2;i++){
			cout << ans << " ";
		}
		n>>=1;
		ans<<=1;
	}
	if(n==3) cout << ans << " " << ans << " " << ans*3 << endl;
	else if(n==2) cout << ans  << " " << ans*2 << endl;
	else cout << ans << endl;
} 
