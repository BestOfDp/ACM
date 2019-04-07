#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,num;
};
vector<node> v;
int a[300005];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int current=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			current++;
		}else{
			node temp;
			temp.c = a[i-1];
			temp.num = current;
			current = 1;
			v.push_back(temp);
		}
	}
	node temp;
	temp.c = a[n-1];
	temp.num = current;
	v.push_back(temp);
	
	int l=0;
	int r=v.size()-1;
	int ans = n;
	while(v[l].c==v[r].c){
		if(v[l].num > v[r].num){
			ans -= v[r].num;
			r--;
		}else{
			ans -= v[l].num;
			l++;
		}
	}
	cout << ans-1 << endl;
}
