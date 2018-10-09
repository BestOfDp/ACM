#include<bits/stdc++.h>
using namespace std;
struct node{
	int cnt;
	int index;
	string s;
}po[105];
int a[105];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=100;i++) {
		po[i].cnt=0;
		po[i].index=0;
		po[i].s="";	
	}
	for(int i=0;i<n;i++){
		cin >> a[i];
		po[a[i]].cnt++;
	}
	int cnt=0;
	int flag=0;
	for(int i=1;i<=100;i++){
		if(po[i].cnt==1){
			cnt++;
		}
		if(po[i].cnt >= 3) flag=1;
	}
	if(cnt%2==1 && !flag){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		int index;
		int mid = cnt/2;
		for(int i=0;i<n;i++){
			if(po[a[i]].cnt>=3) index=i;
		}
		for(int i=0;i<n;i++){
			if(i==index && cnt%2==1){
				continue;
			}
			if(po[a[i]].cnt==1 && mid){
				po[a[i]].s = po[a[i]].s + "A";
				mid--; 
			}else{
				po[a[i]].s = po[a[i]].s + "B";
			}
		}
		if(cnt%2==1){
			po[a[index]].s = "A";
			for(int i=1;i<po[a[index]].cnt;i++){
				po[a[index]].s = po[a[index]].s + "B";
			}
		}
		for(int i=0;i<n;i++){
			cout << po[a[i]].s[po[a[i]].index++];
		}
	}
} 
