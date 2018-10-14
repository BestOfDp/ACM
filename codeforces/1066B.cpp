#include<bits/stdc++.h>
using namespace std;
int a[1005];
int vis[1005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	int pos=-1;
	int ans=0;
	int pre=0;
	int sum=0;
	while(1){
		int next = pos+m;
		next = min(next,n-1);
		int flag=1;
		for(int i=next;i>=pre;i--){
			
			if(a[i]==1){
				a[i]=2;
				flag=0;
				ans++;
				for(int j=max(0,i-(m-1));j<=min(i+(m-1),n-1);j++){
					if(vis[j]==0){
						vis[j]=1;
						sum++;	
					}
					if(sum==n){
						cout << ans << endl;
						return 0;
					}
				} 
				pos=i+m-1;
				pre=i;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	for(int i=0;i<n;i++) if(vis[i]==0){
		cout << -1 << endl;
		return 0;	
	} 
}
