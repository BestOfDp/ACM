#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,index;
}po[200005];
int cmp(node a,node b){
	return a.a < b.a;
}
int main()
{
	int n;
	cin >> n;
	int pre1=0;
	long long ans = 0;
	int pre2=0;
	for(int i=0;i<2*n;i++){
		cin >> po[i].a;
		po[i].index = i;
	}	
	sort(po,po+2*n,cmp);
	for(int i=0;i<2*n;){
//		cout << i << endl;
		int ans1 = abs(po[i].index - pre1) +abs(po[i+1].index - pre2);
		int ans2 = abs(po[i].index - pre2) +abs(po[i+1].index - pre1);
		if(ans1 <= ans2){
			pre1 = po[i].index;
			pre2 = po[i+1].index;
		}else{
			pre1 = po[i+1].index;
			pre2 = po[i].index;
		}
		ans += min(ans1,ans2);
//		cout << ans << endl;
		i+=2;
	}
	cout <<  ans << endl;
} 
