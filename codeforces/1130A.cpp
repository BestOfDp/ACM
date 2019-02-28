#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	int n;
	cin >> n;
	int cnt1=0;
	int cnt2=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] >0) cnt1++;
		else if(a[i]<0) cnt2++;
	}
	sort(a,a+n);
	int number = (n+1)/2;
	int total = n;
	if(cnt1>=number){
		for(int i=1000;i>=0;i--){
			if(i!=a[n-1]){
				cout << i << endl;
				return 0;
			}
		}
	}else if(cnt2>=number){
		for(int i=-1000;i<0;i++){
			if(i!=a[0]){
				cout << i << endl;
				return 0;
			}
		}
	}else{
		cout << 0 << endl;
	}

}
