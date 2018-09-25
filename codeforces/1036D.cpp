#include<bits/stdc++.h>
using namespace std;
long long a[300005],b[300005];
int main()
{
	int n,m;
	long long sum1=0,sum2=0;
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum1+=a[i];
	}
	cin >> m;
	for(int i=0;i<m;i++){
		scanf("%lld",&b[i]);
		sum2+=b[i];
	}
	if(sum1!=sum2){
		cout << -1 << endl;
		return 0; 
	}
	sum1=0;sum2=0;
	int index1=0;
	int index2=0;
	int ans=0;
	while(index1<n && index2<m){
		if(sum1==sum2){
			sum2+=b[index2++];
			sum1+=a[index1++];
			ans++;
		}else if(sum1 > sum2){
			sum2+=b[index2++];
		}else{
			sum1+=a[index1++];
		}
	}
	cout << ans << endl;
}
