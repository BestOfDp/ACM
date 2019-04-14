#include<iostream>
#include<map>
#include<algorithm>
#include<vector> 
using namespace std;
int a[10000];
int b[10000];
int c[10000];
int d[10000];
vector<int>v;
map<int,int>ma;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v.push_back(a[i]+b[j]);
		}
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int tt = c[i]+d[j]; 
//			cout << ma[tt*-1] << endl;
			ans += upper_bound(v.begin(),v.end(),tt*-1) - lower_bound(v.begin(),v.end(),tt*-1);
		}
	}
	printf("%d\n",ans);
}
