#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n,k;
	cin >> n >> k;
	int cnt11=0;
	int cnt22=0;
	for(int i=0;i<n;i++){
		cin >> a[i];	
		if(a[i]==1) cnt11++;
		else cnt22++;
	}
	int ans=0;
	for(int i=0;i<k;i++){
		int cnt1=0;
		int cnt2=0;
		for(int j=i;j<n;){
			if(a[j]==1) cnt1++;
			else cnt2++;
			j+=k;
		}
		cnt1 = cnt11 - cnt1;
		cnt2 = cnt22 - cnt2;
		ans = max(ans,abs(cnt1-cnt2));
	}
	cout << ans << endl;
} 

