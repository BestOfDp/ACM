#include<iostream>
#include<map>
#include<set>
using namespace std;
int a[1000005];
map<int,int>ma;
int main()
{
	int n;
	scanf("%d",&n);
	set<int>s;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	int sum=s.size();
	int ans=1e7;
	int cur = 0;
	int l=0,r=0;
	while(1){
		if(r>=n){
			if(cur==sum){
				ans = min(ans,r-l);
			}
			if(ma[a[l]]==1){
				cur--;
			}
			ma[a[l]]--;
			l++;
		}
		if(l==n){
			break;
		}
		if(cur<sum){
			if(ma[a[r]]==0){
				cur++;
			}
			ma[a[r]]++;
			r++;
		}else{
			ans = min(ans,r-l);
			if(ma[a[l]]==1){
				cur--;
			}
			ma[a[l]]--;
			l++;
		}
	}
	printf("%d\n",ans);
}
