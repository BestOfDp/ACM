#include<bits/stdc++.h>
using namespace std; 
int run(int n){
	if(n%400==0 || (n%4==0 && n%100!=0)) return 1;
	else return 0; 
}
int pri[12]={2,3,5,7,11,13,17,19,23,29,31};
int judge(int x){
	for(int i=0;i<11;i++){
		if(x==pri[i]) return 1;
	}
	return 0;
}
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		int ans=0;
		int flag=0;
		while(1){
			if(flag==1) break;
//			cout << a << " " << b  << " " << c << endl;
			int day = c;
			if(run(a) && b==2) day--;
			if(mon[b]+1==day){
				b++;
				c=1;
			}
			if(b==13){
				a++;
				b=1;
			}
			if(a==d && b==e && c==f) {
				flag=1;
			}
			if(judge(b) && judge(c)){
				ans++;
			}
			c++; 
		}
		cout << ans << endl;
	}
}
