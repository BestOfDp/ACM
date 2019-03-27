#include<bits/stdc++.h>
using namespace std;
int a[1000005];

int find_root(int x){
    int root = x;
    while(a[root]!=root){
        root = a[root];
    }
    int t; 
    // Â·¾¶Ñ¹Ëõ 
    while (root != x) 
	{ 
		t = a[x]; 
		a[x] = root; 
		x = t;
	}
    return x;
}

void merge(int x,int y){
    int father_x = find_root(x);
    int father_y = find_root(y);
    if(father_x == father_y) return;
    a[father_y] = father_x;

}

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int l,r;
	for(int i=0;i<=n;i++) a[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d %d",&l,&r);
		merge(l,r);
	}	
	for(int i=0;i<k;i++){
		scanf("%d %d",&l,&r);
		if(find_root(l)==find_root(r)){
			printf("YES\n");
		}else printf("NO\n");
	}	
} 
