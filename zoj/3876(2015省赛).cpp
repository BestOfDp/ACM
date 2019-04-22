#include<bits/stdc++.h>
using namespace std;
int isy(int y){
	if((y%4==0 && y%100!=0) || y%400==0) return 1;
	return 0;
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long day=0;
		for(int i=1928;i<n;i++){
			day += 365;
			if(isy(i)==1){
				day++;
			}
		}
		day+=(31+28+31+30);
		if(isy(n)){
			day++;
		}
		day %= 7;
		if(day==0){
			cout << 6 << endl;
		}else if(day==1){
			cout << 9 << endl;
		}else if(day==2){
			cout << 6 << endl;
		}else if(day==3){
			cout << 5 << endl;
		}else if(day==4){
			cout << 5 << endl;
		}
		else if(day==5){
			cout << 5 << endl;
		}else{
			cout << 5 << endl;
		}
	}
 } 
