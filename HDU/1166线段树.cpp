#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int sum[maxn<<2];

void pushup(int rt){
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&sum[rt]);
		return;
	}
	int m = (l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int p,int add,int l,int r,int rt){
	if(l==r){
		sum[rt] += add;
		return;
	}
	int m = (l+r)>>1;
	if(p<=m){
		update(p,add,l,m,rt<<1);
	}else{
		update(p,add,m+1,r,rt<<1 | 1);
	}
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L<=l && r<=R){
		return sum[rt];
	}
	int m = (l+r) >> 1;
	int ret=0;
	if(L <= m) ret+=query(L,R,l,m,rt<<1);
	if(R > m) ret+=query(L,R,m+1,r, rt<<1 | 1);
	return ret;
}
int main()
{
	int t;
	cin >> t;
	int index=1;
	while(t--){
		int n;
		cin >> n;
		cout << "Case " << index++ << ":"<< endl;
		build(1,n,1);
		string op;
		while(cin >> op){
			if(op[0] =='E') break;
			int a,b;
			cin >> a >> b;
			if(op[0]=='Q') cout << query(a,b,1,n,1) << endl;
			else if(op[0]=='S') update(a,-b,1,n,1);
			else update(a,b,1,n,1);
		}
	}	
} 
