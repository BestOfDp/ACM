#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int index;
}po[20005];

struct t{
	int a,b,c;
}; 
int cmp(node a,node b){
	if(a.a == b.a){
		if(a.b==b.b){
			return a.c < b.c;
		}
		return a.b < b.b;
	}
	return a.a < b.a;
}
t time(t tt){
	if(tt.c >=60){
		tt.b += (tt.c)/60;
		tt.c = tt.c % 60;
	}
	if(tt.b >= 60){
		tt.a += (tt.b)/60;
		tt.b = tt.b % 60;
	}
	return tt;
}

// t1 < t2
int judge(t t1,t t2){
	if(t1.a == t2.a){
		if(t1.b == t2.b){
			return t1.c <= t2.c;
		}else if(t1.b <= t2.b) return 1;
		else return 0;
	}else if(t1.a <= t2.a) return 1;
	else return 0;
}
int main(){
	int tttt;
	scanf("%d",&tttt);
	while(tttt--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d:%d:%d",&po[i].a,&po[i].b,&po[i].c);
			po[i].index = i+1;
		}
		sort(po,po+n,cmp);
		vector<int>v;
		v.clear();
		v.push_back(po[0].index);
		t temp;
		temp.a = po[0].a;
		temp.b = po[0].b;
		temp.c = po[0].c+m;
		temp = time(temp);
		for(int i=1;i<n;i++){
			t now;
			now.a = po[i].a;
			now.b = po[i].b;
			now.c = po[i].c;
			if(judge(temp,now)){
				v.push_back(po[i].index);
				now.c += m;
				temp = time(now);
			}
		}
		sort(v.begin(),v.end());
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++){
			if(i!=0) printf(" "); 
			printf("%d",v[i]); 
		}
		printf("\n");
	}
}
