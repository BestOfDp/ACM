#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,index;
}po[50005];
int cmp(node a,node b){
	if(a.l == b.l) return a.r < b.r;
	return a.l <b.l;
}

int cmp2(node a,node b){
	return a.r > b.r;
}

int cmp3(int a,int b){
	return a < b;
}
node a[5];
int inner(){
	sort(a,a+3,cmp);
	return (a[1].l <= a[0].r && a[1].r >= a[2].l && a[2].l <= a[0].r);
}
int main()
{
	int t;
	cin >>t;
	while(t--){
		int n;
		vector<int>ans;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> po[i].l >> po[i].r;
			po[i].index = i+1;
		}
		sort(po,po+n,cmp);
		a[0] = po[0];
		a[1] = po[1];
		for(int i=2;i<n;i++){
			a[2] = po[i];
			if(inner()){
				sort(a,a+3,cmp2);
				ans.push_back(a[0].index);
				swap(a[0],a[2]);
			}else sort(a,a+3,cmp2);
		}
		sort(ans.begin(),ans.end(),cmp3);
		cout << ans.size() << endl;
		if(ans.size()==0){
			cout << endl;
		}else{
			for(int i=0;i<ans.size();i++){
				if(i==ans.size()-1){
					cout << ans[i] << endl;
				}else{
					cout << ans[i] << " "; 
				}
			}
		}
	}
}
