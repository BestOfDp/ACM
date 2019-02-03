#include<bits/stdc++.h>
using namespace std;

vector<int>v[100005];
int vis[100005];
int n,m;
priority_queue<int,vector<int>,greater<int> > q;
void bfs(){
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int top = q.top();
		q.pop();
		cout << top << " ";
		for(int i=0;i<v[top].size();i++){
			int number = v[top][i];
			if(vis[number]==0){
				vis[number]=1;
				q.push(number); 
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
}
