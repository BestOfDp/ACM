#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000006;
struct node{
	int l,r,v;
}po[maxn<<2];
void pushup(int rt){
	po[rt].v = max(po[rt<<1].v ,po[rt<<1 | 1].v);
}

void build(int l,int r,int rt){
	po[rt].l = l;
	po[rt].r = r;
	if(r==l){
		scanf("%d",&po[rt].v);
		return;
	}
	int mid = (l+r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1 | 1);
	pushup(rt);
}

void update(int rt,int k,int i){
	// р╤вс╫з╣Ц 
	if(po[rt].l==po[rt].r){
		po[rt].v = i;
		return;
	}
	int mid = (po[rt].l + po[rt].r) >> 1;
	if(k<=mid) update(rt<<1,k,i);
	else update(rt<<1 | 1,k,i);
	pushup(rt);
}

int query(int l,int r,int rt){
	if(l<=po[rt].l && po[rt].r <= r){
		return po[rt].v;
	}
	
	int maxn = 0;
	int mid = (po[rt].l + po[rt].r) >> 1;
	if(l<=mid) maxn = max(query(l,r,rt<<1),maxn);
	if(r>mid) maxn = max(maxn,query(l,r,rt<<1|1));
	return maxn; 
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		build(1,n,1);
		for(int i=0;i<m;i++){
			string op;
			int a,b;
			op.assign(50,'\n');
			scanf("%s",op.c_str());
			scanf("%d%d",&a,&b);
			if(op[0]=='Q') printf("%d\n",query(a,b,1));
			else update(1,a,b);
		}	
	}
}
