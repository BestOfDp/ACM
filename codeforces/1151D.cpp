#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
}po[100005];
int cmp(node a,node b){
	return (a.a - a.b) > (b.a - b.b);
}
int main()
{
	long long n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> po[i].a >> po[i].b;
	}
	sort(po,po+n,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans += po[i-1].a * (i-1) + po[i-1].b *(n-i);
//		cout << po[i-1].a << " " << po[i-1].b << endl;
//		cout << ans << endl;
	}
	cout << ans << endl;
}
