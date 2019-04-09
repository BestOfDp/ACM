#include<iostream>
#include<stdio.h>
using namespace std;
int par[200005];
int rank[200005];
int n,m;
void init(int n){
	for(int i=1;i<=n;i++){
		par[i] = i;
		rank[i]= 0;
	}	
}

int find(int x){
//	int temp = x;
//	while(par[temp]!=x){
//		temp = par[temp];
//	}
//	return temp;
	if(par[x]==x) return x;
	else return par[x] = find(par[x]);
}

bool same(int x,int y){
	return find(x) == find(y);
}

void merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init(3*n);
	int ans = 0;
	int t,x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&t,&x,&y);
		if(x>n || y>n || x<=0 || y <=0){
			ans++;
			continue;
		}
		if(t==2 && x==y){
			ans++;
			continue;
		}
		if(t==1){
			if(same(x,y+n) || same(x,y+2*n)) ans++;
			else{
				merge(x,y);
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
		}else{
			if(same(x,y) || same(x,y+2*n)) ans++;
			else{
				merge(x,y+n);
				merge(x+n,y+2*n);
				merge(x+2*n,y);
			}
		}
	}	
	printf("%d\n",ans);
} 
