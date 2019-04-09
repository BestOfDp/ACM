#include<bits/stdc++.h>
using namespace std;
map<int,map<string,int> >ma;
string name[1000];
int tt[500];
int main()
{
	
	int t;
	scanf("%d",&t);
	while(t--){
		ma.clear();
		int n,m;
		scanf("%d %d",&n,&m);
		int c;
		scanf("%d",&c);
		for(int i=0;i<c;i++){
			string an;
			an.resize(220);
			scanf("%s",&an[0]);
			name[i] = an;
		}
		for(int i=0;i<m;i++){
			int nu;
			scanf("%d",&nu);
			for(int j=0;j<nu;j++){
				string ss;
				ss.resize(220);
				scanf("%s",&ss[0]);
				ma[i][ss] = 1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int ttemp;
				scanf("%d",&ttemp);
				tt[j] = ttemp;
			}
			int ssum=0;
			string aaans;
			for(int j=0;j<c;j++){
				int sum=0;
				
				for(int k=0;k<m;k++){
					int exist = ma[k][name[j]];
					if(tt[k]==exist){
						sum++;
					}else break;
				}
				if(sum==m){
					aaans = name[j];
					ssum++;
				}
				if(ssum>1){
					break;
				}
			}
			if(ssum==1){
				printf("%s\n",aaans.c_str());
			}else{
				printf("Let's go to the library!!\n");
			}
		}
	}
}
