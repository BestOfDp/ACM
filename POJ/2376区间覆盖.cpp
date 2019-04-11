#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
}po[25005];
int cmp(node a,node b){
	if(a.s == b.s){
		return a.e > b.e;
	}
	return a.s < b.s;
}
int main()
{
	int n,l;
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++){
		scanf("%d %d",&po[i].s,&po[i].e);
	}
	sort(po,po+n,cmp);
	int ans=0;
	if(po[0].s>1){
		ans=-1;
	}else{
		int index=0;
		int left,right;
		while(1){
			left = po[index].s;
			right = po[index].e;
//			printf("%d %d\n",left,right);
			int maxn=right;
			for(int i=index+1;i<n;i++){
				if(po[i].s <= right+1){
					if(po[i].e > maxn){
						maxn = po[i].e;
						index = i;
					}
				}else{
					break;
				}
			}
			ans++;
			if(maxn==right)
				break;
			right = maxn;
		}
		if(right!=l){
			ans=-1;
		}
	}
	printf("%d\n",ans);
} 
