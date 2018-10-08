#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b==0 ? a:gcd(b,a%b);
}

int vis[15000005];
int prime[15000005];
int minprime[15000005];
int cnt[15000005];
int k=0;
void sieve(int n) {
	for(int i=2; i<=n; i++) {
		if(!vis[i]) {
			minprime[i]=i;
			prime[++k]=i;
		}
		for(long long j=1; j<=k&&(long long)i*prime[j]<=n; j++) {
			minprime[(long long)i*prime[j]]=prime[j];
			vis[(long long)i*prime[j]]=1;
			if(!(i%prime[j])) break;
		}
	}
}
void div(int x)
{
	if(x==1 || !vis[x])
	{
		cnt[x]++;
		return;
	}
	while(x>1)
	{
		int y = minprime[x];
		cnt[y]++;
		while(x%y==0 && x!=-1) x/=y;
	}
}
vector<int>v;
int main()
{
	sieve(15000000);
	int n;
	cin >> n;
	int number;
	int min_gcd=0;
	for(int i=0;i<n;i++)
	{
		cin >> number;
		v.push_back(number);
		min_gcd = gcd(min_gcd,number);
	}
	int len=v.size();
	for(int i=0;i<len;i++)
	{
		v[i]/=min_gcd;	
		div(v[i]);
	}
	int maxn=0;
	for(int i=2;i<=15000000;i++) maxn = max(maxn,cnt[i]);
	if(maxn==0) cout << -1 << endl;
	else cout << n-maxn << endl;
} 
