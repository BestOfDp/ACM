#include<iostream>
#include<string>
using namespace std;
char  c[20005];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> c[i];
	string ans="";
	int l=0;
	int r=n-1;
	while(ans.size()!=n){
		if(c[l] > c[r]){
			ans = ans + c[r];
			r--;
		}else if(c[l] < c[r]){
			ans = ans + c[l];
			l++;
		}else{
			int tl = l;
			int tr = r;
			int flag=1;
			while(1){
				if(tl==tr) break;
				if(c[tl]>c[tr]){
					flag=0;
					break;
				}
				if(c[tl]!=c[tr]) break;
				tl++;
				tr--;
			}
			if(flag==0){
				ans = ans + c[r];
				r--;
			}else{
				ans = ans + c[l];
				l++;
			}
		}
	}
	for(int i=1;i<=ans.size();i++){
		cout << ans[i-1];
		if(i%80==0){
			cout << endl;
		}
	} 
	
} 
