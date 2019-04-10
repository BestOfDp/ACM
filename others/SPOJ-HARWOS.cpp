#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	int t;
	cin >> t;
	int index=1;
	while(t--){
		int ans=0;
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			for(int j=n-1;j>=0;j--){
				a[i]=-1;
				if(s[j]=='1'){
					a[i]=j;
					break; 
				}
			}
		}
		for(int i=0;i<n;i++){
			int pos=-1;
			for(int j=i;j<n;j++){
				if(a[j]<=i){
					pos = j;
					break;
				}
			}
			
			for(int j=pos;j>i;j--){
				swap(a[j],a[j-1]);
				ans++;
			}
		}
		cout << "Case #" << index++ <<": " << ans << endl;
	}
}
