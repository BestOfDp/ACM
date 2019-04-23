#include<bits/stdc++.h>
using namespace std;
int number = 2059;
long long isy(long long y){
	if((y%400==0) || (y%4==0 && y%100!=0)) return 1;
	return 0;
}
long long mon[15]={31,31,28,31,30,31,30,31,31,30,31,30,31};

int getW(int y,int m,int d){
	if(m<=2){
		y--;
		m+=12;
	}
	int dis=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return dis;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long y,m,d,nn;
		scanf("%lld%lld%lld%lld",&y,&m,&d,&nn);
		long long add =  400 * (nn/2058);
		nn %= 2058;
		y += add;
		long long dis=getW(y,m,d);
		while(1){
			long long max_mon = mon[m];
			if(isy(y)==1 && m==2){
				max_mon++;
			}
			if(d == max_mon+1){
				d = 1;
				m++;
			}
			if(m==13){
				m=1;
				y++;
			}
			if(dis%7==0 && (d==1 || d==11 || d==21)){
				nn--;
				if(nn==0) break;
			}
			dis++;
			d++;
		}
		printf("%lld %lld %lld\n",y,m,d);
	}
}
