#include<bits/stdc++.h>
using namespace std;
int a[1005];

int find(int x){
	int ans = x;
	while(a[ans]!=-1){
		ans = a[ans];
	}
	return ans;
}
void merge(int x,int y){
	int pre_x = find(x);
	int pre_y = find(y);
	if(pre_x==pre_y) return;
	a[pre_y] = pre_x;
}
int main()
{
	int n;
	int m; 
	int x,y;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		scanf("%d",&m);
		memset(a,-1,sizeof(a));
		for(int i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			if(x>y) swap(x,y);
			merge(x,y); 
		} 
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(a[i]==-1) ans++;
		} 
		printf("%d\n",ans-1);
	}
} 
