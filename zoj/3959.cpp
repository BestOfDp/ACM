#include<bits/stdc++.h>
using namespace std;
int a[500];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int flag=1;
		int cnt=0;
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if(a[i]==1){
				flag=0;
				cnt++;
			}	
		}
		if(n<10 || n>13 || cnt<2) {
			printf("No\n");
			continue;
		}
		
		sort(a,a+n);
		if(a[0]!=1) {
			printf("No\n");
			continue;
		}
		int tt=1;
		for(int i=1;i<n-1;i++){
			if(a[i]-a[i-1]>2){
				tt=0;
			}
		}
		if(tt==1) printf("Yes\n");
		else printf("No\n");
		
		
	}
}
