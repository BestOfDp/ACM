#include<stdio.h>
#include<deque>
#include<vector>
using namespace std;
int n,m;
struct node{
	int id,val;
};
node mmin[1000005];
node mmax[1000005];
vector<int>ans;
vector<int>ans1;
int lmin,rmin,lmax,rmax;

void add(int val,int index){
	while(rmin>=lmin && mmin[rmin].val > val) rmin--;
	mmin[++rmin].val = val;
	mmin[rmin].id = index;
	while(mmin[lmin].id <= index-m) lmin++;
	if(index<m-1) return;
	ans.push_back(mmin[lmin].val);
}

void add1(int val,int index){
	while(rmax>=lmax && mmax[rmax].val < val) rmax--;
	mmax[++rmax].val = val;
	mmax[rmax].id = index;
	while(mmax[lmax].id <= index-m) lmax++;
	if(index<m-1) return;
	ans1.push_back(mmax[lmax].val);
}
int main()
{
	scanf("%d %d",&n,&m);
	lmin=0,rmin=-1,lmax=0,rmax=-1;
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		add(x,i);
		add1(x,i);	
	} 
	for(int i=0;i<ans.size();i++){
		if(i==0) printf("%d",ans[i]);
		else printf(" %d",ans[i]);
	}
	printf("\n");
	for(int i=0;i<ans1.size();i++){
		if(i==0) printf("%d",ans1[i]);
		else printf(" %d",ans1[i]);
	}	
} 
