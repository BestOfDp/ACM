#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qp(ll a,ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll ans = 0;
    if(b&1){
    	ans = qp(a,(b-1)/2);
    	return  ans*ans*a % 2;
	}else{
		ans = qp(a,b/2);
    	return  ans*ans % 2;
	}
}
int main()
{
	ll n,m;
	cin >> n >> m;
	ll sum=0;
	ll t;
	for(int i=m-1;i>=0;i--){
		cin >> t;
		sum += (t*qp(n,i));
	}	
	if(sum%2==1) cout << "odd" << endl;
	else cout << "even" << endl; 
} 
