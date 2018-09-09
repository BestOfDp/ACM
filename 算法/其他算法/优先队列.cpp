#include<bits/stdc++.h>
using namespace std;
struct node{
	int cnt;
	int dis;
	double x;
	friend bool operator < (node n1,node n2){
		return n1.x < n2.x;
	}
}po[10005];
priority_queue<node> q;
int main()
{
	int n,m,k,pre,now;
	cin >> n >> m >> k >> pre;
	for(int i=1;i<n;i++){
		cin >> now;
		po[i].cnt = 1;
		po[i].dis = now - pre;
		po[i].x = 1.0 *po[i].dis/po[i].cnt;
		q.push(po[i]);
		pre = now;
	}
	for(int i=1;i<=k;i++){
		node temp = q.top();
		q.pop();
		temp.cnt++;
		temp.x = 1.0*temp.dis/temp.cnt;
		q.push(temp);
	}
	node temp = q.top();
	printf("%.1lf\n",temp.x);
}
