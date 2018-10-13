#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n;
	cin >> n;
	int l=0,r=0;
	string s;
	int t;
	for(int i=0;i<n;i++){
		cin >> s >> t;
		if(i==0){
			a[t]=r;
			r++;
			l--;
			continue;
		}
		if(s=="L") a[t]=l--;
		else if(s=="R") a[t]=r++;
		else cout << min(abs(a[t]-l),abs(a[t]-r))-1 << endl;
	}
}
