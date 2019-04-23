#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M=100005;
struct node{
	long long to,va,mo;
};
vector<node>G[M];
long long n,m;
struct Hp{long long a,b;bool operator <(const Hp &x)const{return b>x.b;}};
priority_queue<Hp>Q;
bool vis[M];
long long dis[M];
long long mon[M];
void Dij(){
    memset(vis,0,sizeof(vis));
    for(long long i=0;i<=n;i++){
    	dis[i] = 1e18;
    	mon[i] = 1e18;
	}
    while(!Q.empty())Q.pop();
    dis[0]=0,Q.push((Hp){0,0});
    while(!Q.empty()){
        long long u=Q.top().a;Q.pop();
        if(vis[u])continue;vis[u]=1;
        for(long long i=0;i<G[u].size();i++){
            if(dis[G[u][i].to]>dis[u]+G[u][i].va)
            {
                dis[G[u][i].to]=dis[u]+G[u][i].va,Q.push((Hp){G[u][i].to,dis[G[u][i].to]});
				mon[G[u][i].to]= G[u][i].mo;
			}else if(dis[G[u][i].to]==dis[u]+G[u][i].va){
				mon[G[u][i].to]= min(mon[G[u][i].to],G[u][i].mo);
			}
        }
    }
}
long long st[M];
long long end[M];
long long cost1[M];
long long cost2[M];
int main() {
	long long t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(long long i=0;i<m;i++){
			long long v,mo;
			scanf("%lld %lld %lld %lld",&st[i],&end[i],&v,&mo);
			G[st[i]].push_back((node){end[i],v,mo});
        	G[end[i]].push_back((node){st[i],v,mo});
		}
		
		Dij();
		long long length = 0;
		long long money = 0;
		for(long long i=1;i<n;i++){
			length += dis[i];
			money += mon[i];
		}
		printf("%lld %lld\n",length,money);
		while(!Q.empty()) Q.pop();
		for(long long i=0;i<=n;i++){
			G[i].clear();
		}
	}
}
