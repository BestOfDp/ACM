#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int index;
}po[200005];

map<int,int> m;
priority_queue<int,vector<int>,greater<int> > q;
int cmp(node a,node b){
	return a.x < b.x;
} 
int cmp_index(node a,node b){
	return a.index < b.index;
} 
int main()
{
	int n,m1,d;
	cin >> n >> m1 >> d; 
	for(int i=0;i<n;i++){
		cin >> po[i].x;
		po[i].index = i;
	}
	sort(po,po+n,cmp);
	m[po[0].x]=1;
	int num=1;
	q.push(po[0].x);
	for(int i=1;i<n;i++){
		int t_num = q.top();
		if(po[i].x - t_num > d){
			m[po[i].x] = m[t_num];
			q.pop();
		}else{
			m[po[i].x] = ++num;
		}
		q.push(po[i].x);
	}
	sort(po,po+n,cmp_index);
	cout << num << endl;
	for(int i=0;i<n;i++){
		cout << m[po[i].x] << " ";
	}
	cout << endl;
} 
