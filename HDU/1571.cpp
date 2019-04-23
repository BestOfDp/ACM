#include<bits/stdc++.h>
using namespace std;
long long a[50][50];
int main()
{
	int n;
	while(cin >> n){
			//  Ä¿±ê time 
		vector<pair<int,int> >v;
		vector<pair<int,int> >::iterator iter;
		long long ans=0;
		if(n==0) break;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j];
			}
		}
		int op;
		cin >> op;
		string oper;
		int index=0;
		int t;
		int sum=0;
		for(int i=0;i<op;i++){
			cin >> oper;
			if(oper[0]=='U'){
				cin >> t;
				if(v.size()==7) continue;
				if(t==index) continue;
				v.push_back(make_pair(t,i));
			}else{
				if(v.size()==0) continue;
				int end = v.front().first;
				ans += a[index][end];
				index = end;
				iter = v.begin();
				while(iter!=v.end()){
					if((*iter).first==index){
						iter=v.erase(iter);
					}else iter++;
				}
			}
		}
		cout << ans << endl;
	}
}	
