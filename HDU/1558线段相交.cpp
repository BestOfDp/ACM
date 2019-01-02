#include<bits/stdc++.h>
using namespace std;

struct node{
	double x,y;
}pl[1005],pr[1005];


int a[1005];
int ans[1005];

double mul(node a,node c,node b){
	return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}

int judge(node a,node b,node c,node d){
if(min(a.x,b.x)>max(c.x,d.x)) return false;
	if(min(a.y,b.y)>max(c.y,d.y)) return false;
	if(max(a.x,b.x)<min(c.x,d.x)) return false;
	if(max(a.y,b.y)<min(c.y,d.y)) return false;
	if(mul(a,c,b)*mul(a,b,d)<0) return false;
	if(mul(c,a,d)*mul(c,d,b)<0) return false;
	return true;
}

int find(int  x){
	int ans = x;
	while(a[ans]!=-1){
		ans = a[ans];
	}
	return ans;
}

void merge(int x,int y){
	int father_x = find(x);
	int father_y = find(y);
	if(father_x != father_y){
		a[father_y] = father_x;
		ans[father_x] += ans[father_y];
		ans[father_y] = 0;
	}
} 
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		char tt;
		int query;
		cin >> n;
		for(int i=0;i<=n;i++){
			a[i]=-1;
			ans[i]=1;
		}
		int index=1;
		for(int i=0;i<n;i++){
			cin >> tt;
			if(tt=='P'){
				cin >> pl[index].x >> pl[index].y >> pr[index].x >> pr[index].y;
				for(int j=1;j<index;j++){
					if(judge(pl[index],pr[index],pl[j],pr[j])){
						merge(index,j);	
					}
				}
				index++;
			}else{
				cin >> query;
				cout << ans[find(query)] << endl;
			}
		}
		if(t!=0){
			cout << endl;
		}
	}
} 
