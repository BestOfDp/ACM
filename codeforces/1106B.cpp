#include<bits/stdc++.h>
using namespace std;
struct node{
	int index;
	long long number,cost;
}po[100005];

map<int,int>re;
int cmp(node a,node b){
	if(a.cost==b.cost) return a.index < b.index;
	return a.cost < b.cost;
}
int n,m;
void display(){
	for(int i=0;i<n;i++){
		cout << po[i].index << " " << po[i].number << " " << po[i].cost << endl; 
	}
}
int main()
{
	cin >> n >> m;
	long long sum=0;
	for(int i=0;i<n;i++){
		po[i].index = i;
		cin >> po[i].number;
		sum+=po[i].number;
	}
	for(int i=0;i<n;i++){
		cin >> po[i].cost;
	} 
	sort(po,po+n,cmp);
	for(int i=0;i<n;i++){
		re[po[i].index] = i;
	}
	int index=0;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		if(sum >= y){
			long long ans=0;
			sum-=y;
			int now_index=re[x-1];
			if(po[now_index].number >= y){
				ans += (y*po[now_index].cost);
				po[now_index].number -= y;
			}else{
				ans += (po[now_index].number*po[now_index].cost);
				y-=po[now_index].number;
				po[now_index].number = 0;
				while(1){
					if(y==0) break;
					while(po[index].number==0) index++;
					long long number = po[index].number;
					long long cost = po[index].cost;
					if(number > y){
						ans += y*cost;
						po[index].number -=y;
						y=0;
					} else{
						ans += number * cost;
						po[index].number = 0;
						y-= number;
					}
				}
			}
			cout << ans << endl;
		}else{
			cout << 0 << endl;
			sum=0;
		}
	}
} 
