#include<bits/stdc++.h>
using namespace std;
long long a[300005];
int n;
long long getMax(){
	long long sum=0;
	long long maxn = 0;
	for(int i=0;i<n;i++){
		if(sum+a[i]>0){
			sum+=a[i];
			maxn = max(sum,maxn);
		}else{
			sum = 0;
		}
	}
	return maxn;
}

int l, r;
int ans_l,ans_r;
long long getMin(){
	long long sum=0;
	long long maxn = 0;
	l = 0;
	for(int i=0;i<n;i++){
		if(sum+a[i]>0){
			sum = 0;
			l = i;
		}else{
			sum+=a[i];
			if(sum <= maxn){
				maxn = sum;
				ans_l = l;
				ans_r = i;
				r = i;
			}
		}
	}
	cout << ans_l << " " << ans_r << endl;
//	cout << maxn << endl;
	return maxn;
}
int main()
{
	int m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	if(m>0){
		cout << m * getMax() << endl;
	}else if(m<=0){
		long long ans = m * getMin();
		for(int i=ans_l;i>=0;i--){
			if(a[i]<0) break;
			ans += a[i];
		}
		for(int i=ans_r+1;i<n;i++){
			if(a[i]<0) break;
			ans += a[i];
		}
		cout << ans << endl;
	}else{
		cout << m * getMax() << endl;
	}
}
