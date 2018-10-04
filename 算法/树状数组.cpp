#include<bits/stdc++.h>
using namespace std;
int a[100005];//原数组 
int t[100005];//树状数组 
int n;
int lowbit(int x) {
	return x & (-x);
}	

// 查询 x的前缀和 
int query(int x)
{
	int ans=0;
	while(x){
		ans+=t[x];
		x-=lowbit(x);
	}	
	return ans;
} 

// 在x位上加num 
void add(int x,int num){
	while(x<=n){
		t[x]+=num;
		x+=lowbit(x);
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		add(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		cout << query(i) << endl;
	}
} 
