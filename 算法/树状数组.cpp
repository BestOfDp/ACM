#include<bits/stdc++.h>
using namespace std;
int a[100005];//ԭ���� 
int t[100005];//��״���� 
int n;
int lowbit(int x) {
	return x & (-x);
}	

// ��ѯ x��ǰ׺�� 
int query(int x)
{
	int ans=0;
	while(x){
		ans+=t[x];
		x-=lowbit(x);
	}	
	return ans;
} 

// ��xλ�ϼ�num 
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
