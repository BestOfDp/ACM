#include<bits/stdc++.h>
using namespace std;
int n,q,c;
double s;
const double eps = 1e-5;
struct node{
	double score;
	int index;
}po[105]; 

node rrr[105];
int coppy(){
	for(int i=1;i<=n;i++){
		rrr[i].score = po[i].score;
		rrr[i].index = po[i].index;
	}
}
//  被攻击的服务器 ,攻击成功 
map<pair<int,int>,set<int> >attack;
int cmp(node a,node b){
//	double num = a.score - b.score;
//	if(num >= eps) return 1;
//	return 0;
	return a.score > b.score;
}
map<int,pair<double,int> > ans;
void init(){
	for(int i=1;i<=n;i++){
		po[i].score = s;
		po[i].index = i;
	}
}
set<int>ok;
set<int>error;
int querypo[105];
int main()
{
	int t;
	scanf("%d",&t);
	map<pair<int,int>,set<int> >::iterator iter;
	set<int>::iterator siter;
	while(t--){
		scanf("%d %d %lf %d",&n,&q,&s,&c);
		init();
		while(c--){
			int att;
			scanf("%d",&att);
			int atter, defer, service;
			attack.clear();
			ok.clear();
			error.clear();
			ans.clear();
			for(int i=0;i<att;i++){
				scanf("%d %d %d",&atter,&defer,&service);
				attack[make_pair(defer,service)].insert(atter); 
			}
			//计算
			for(iter=attack.begin();iter!=attack.end();iter++){
				int dis_num = iter->first.first;
				po[dis_num].score -= n-1;
				set<int> adder = iter->second;
				double ever =  ((double)n-1)/(adder.size());
				
				for(siter=adder.begin();siter!=adder.end();siter++){
					int number = *siter;
					po[number].score += ever;
				}
			}	
			for(int i=1;i<=q;i++){
				ok.clear();
				error.clear();
				for(int j=1;j<=n;j++){
					int temp;
					scanf("%d",&temp);
					if(temp==1){
						ok.insert(j);
					}else{
						error.insert(j);
					}
				}
				double dis_number = n-1;
				if(error.size()==0) continue;
				double add_number = dis_number / ok.size();
				for(siter=error.begin();siter!=error.end();siter++){
					int number = *siter;
					po[number].score -= dis_number;
				}
				for(siter=ok.begin();siter!=ok.end();siter++){
					int number = *siter;
					po[number].score += add_number * error.size();
				}
			}
			ans.clear();
			int query;
			scanf("%d",&query);
			coppy();
			sort(rrr+1,rrr+1+n,cmp);
			int current=1;
			double pre=0;
			for(int i=1;i<=n;i++){
				double num = pre - rrr[i].score;
				if(num > eps ){
					current=i;
				}
				pre = rrr[i].score;
				ans[rrr[i].index] = make_pair(rrr[i].score,current);
			}
			for(int i=0;i<query;i++){
				scanf("%d",&querypo[i]);
				printf("%.8lf %d\n",ans[querypo[i]].first,ans[querypo[i]].second);
			}
			
		}
	}
}
