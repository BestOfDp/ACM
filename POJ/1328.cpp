#include<stdio.h>
#include<math.h> 
#include<algorithm>
using namespace std;
struct node{
	double x,y;
}po[1005];
int n;
int d;
int cmp(node a,node b){
	return a.y < b.y;
}
int main()
{
	int index=1;
	while(scanf("%d%d",&n,&d)!=EOF){
		if(n==0 && d==0) break;
		int ans=1;
		for(int i=0;i<n;i++){
			int x,y;
			
			scanf("%d%d",&x,&y);
			if(y>d) {
				ans = -1;
				continue;	
			}
			po[i].x = (double)x - sqrt((double)(d*d - y*y));
			po[i].y = (double)x + sqrt((double)(d*d - y*y));
		}
		sort(po,po+n,cmp);
		if(ans==1){
			double left = po[0].x;
			double right = po[0].y;
			for(int i=1;i<n;i++){
				if(po[i].x > right){
					ans++;
					right = po[i].y;
				}
			}
		}
		printf("Case %d: %d\n",index++,ans);
	}
}
