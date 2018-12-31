#include<bits/stdc++.h>
using namespace std;
int a[1005];

int find_root(int x){
	int root = x;
	while(a[root]!=-1){
		root = a[root];
	}
	return root;
}
void merge(int x,int y){
	int father_x = find_root(x);
	int father_y = find_root(y);
	if(father_x == father_y) return;
	a[father_y] = father_x;
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		int x,y,l,r;
		cin >> x >> y;
		memset(a,-1,sizeof(a));
		for(int i=0;i<y;i++){
			cin >> l >> r;
			merge(l,r);
		}
		int ans=0;
		for(int i=1;i<=x;i++){
			if(a[i]==-1){
				ans++;
			}
		}
		cout << ans << endl;
	}
}
