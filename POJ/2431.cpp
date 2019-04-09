#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
struct node{
	int dis,oil;
}po[100005]; 
int cmp(node a,node b){
	return a.dis < b.dis;
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> po[i].dis >> po[i].oil;
	}
	int l,r;
	cin >> l >> r;
	for(int i=0;i<n;i++){
		po[i].dis = l - po[i].dis;
	}
	sort(po,po+n,cmp);
	po[n].dis = l; 
	int ans=0;
	int i=0;
	int flag=0;
	priority_queue<int> q;
	int index=0;
	while(i!=n+1){
		int leng = po[i].dis - index;
		while(r<leng){
			if(q.empty()){
				flag=1;
				break;
			}
			r+=q.top();
			q.pop();
			ans++;
		}
		if(flag==1) break; 
		r-=leng;
		index=po[i].dis;
		q.push(po[i].oil);
		i++;
	}
	if(flag){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
} 
