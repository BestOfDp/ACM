#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,index;
};
struct cmp1
{
    bool operator () (const node &a,const node &b) const {
        return a.v <= b.v;
    }
};
node a[200005];
node b[200005];
int cmp(node a,node b){
	return a.v < b.v;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		node temp;
		cin >> temp.v;
		temp.index = i+1;
		a[i] = temp;
	}
	for(int i=0;i<m;i++){
		node temp;
		cin >> temp.v;
		temp.index = i+1;
		b[i] = temp;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		cout << lower_bound(a,a+n,b[i],cmp1()) - a << " ";
	}
	
} 
