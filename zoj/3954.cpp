#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int sss[10] = {0,2,5,5,4,5,6,3,7,6};
int yuan[50][8]={
	{0,1,1,1,1,1,1,1},
	{0,1,0,0,1,1,1,1},
	{0,0,0,1,0,0,1,0},
	{0,0,0,0,0,1,1,0},
	{0,1,0,0,1,1,0,0},
	{0,0,1,0,0,1,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0} 
};
int vis[50];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		memset(vis,0,sizeof(vis));
		set<int>s;
		vector<int>v;
		
		scanf("%d",&n);
		string ss;
		for(int i=1;i<=n;i++){
			int temp;
			scanf("%d",&temp);
			s.insert(temp);
			ss.assign(50,'\n');
			scanf("%s",ss.c_str());
			for(int j=1;j<=7;j++) {
				a[temp][j] = ss[j-1]-'0';	
			}
		}
		string ans="YES";
		set<int>::iterator iter;
		for(iter=s.begin();iter!=s.end();iter++){
			v.push_back(*iter);
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=7;i++){
			string my = "";
			for(int j=1;j<=n;j++){
				int co = v[j-1];
				my.push_back(a[co][i]+'0');
			}
			
			int flag=1;
			for(int k=1;k<=7;k++){
				string old = "";
				if(vis[k]==1) continue;
				for(int j=1;j<=n;j++){
					int co = v[j-1];
					old.push_back(yuan[co][k]+'0');
				}
				if(my==old){
					vis[k]=1;
					flag=0;
					break;
				}
			}
			if(flag){
				ans = "NO";
				break;	
			} 
		}
		printf("%s\n",ans.c_str());
	}
}
