#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int sum=0;
	for(int i=0;i<n;i++){
		a[i]=s[i]-'0';
		sum+=a[i];
	}
	for(int i=2;i<=n;i++){
		if(sum%i==0){
			vector<int>v;
			v.clear();
			int need=sum/i;
			int index=-1;
			int cur_sum=0;
			for(int j=0;j<n;j++){
				cur_sum+=a[j];
				if(cur_sum==need){
					cur_sum=0;
					v.push_back(index);
					index=j;
				}else if(cur_sum>need){
					break;
				}
			}
			if(v.size()==i){
				cout << "YES"<< endl;
				return 0; 
			}
		}
	}
	cout << "NO" << endl;
} 
