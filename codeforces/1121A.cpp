#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,c;
}po[105];
int cmp(node a,node b){
	return a.s < b.s;
}
map<int,vector<node> >ma;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		cin >> po[i].s; 
	}
	for(int i=0;i<n;i++){
		cin >> po[i].c;
		
		ma[po[i].c].push_back(po[i]);
	}
	int ans = 0;
	int id;
	for(int i=0;i<k;i++){
		cin >> id; 
		sort(ma[po[id-1].c].begin(),ma[po[id-1].c].end(),cmp );
		for(int j=0;j< ma[po[id-1].c].size();j++){
			if(ma[po[id-1].c][j].s==po[id-1].s && j!= ma[po[id-1].c].size() -1){
//				cout << j << endl;
//				ans += ma[po[id-1].c].size() - j -1;
				ans ++ ;
			}
		}
	}
	cout << ans << endl;
	
} 
