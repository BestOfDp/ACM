#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}po[200005];
vector<int>v;
int main()
{
	int n,m;
	cin >> n >> m;
	v.push_back(0);
	for(int i=0;i<n;i++){
		cin >> po[i].x >> po[i].y ;
		if(i!=0){
			v.push_back(v[i-1]+po[i].x - po[i-1].y);
		}
	}
	int ans=0;
	for(int l=0,r=0;l<n;l++)
	{
		while(v[r+1]-v[l]<m && r+1<v.size()) r++;
		int len = po[r].y - po[l].x+(m-(v[r]-v[l]));
		ans = max(ans,len);
	}
	cout << ans << endl;
} 
