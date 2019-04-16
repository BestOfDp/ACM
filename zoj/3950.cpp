#include<bits/stdc++.h>
using namespace std;
int inye(int y){
	if((y%400==0) || (y%4==0 && y%100!=0)) return 1;
	return 0;
}
int nine(int y){
	int cnt=0;
	while(y){
		if(y%10==9) cnt++;
		y/=10;
	}
	return cnt;
}
int get(int a,int b,int c){
	return nine(a) + nine(b) + nine(c); 
}
int mon[15]={31,31,28,31,30,31,30,31,31,30,31,30,31};
long long ans[10005][13][35];
int main()
{
	int n;
	scanf("%d",&n);
	int a1=2000,b1=1,c1=1;
	int flag=0;
	int sum=0;
	while(1){
		if(flag) break;
		if(inye(a1) && b1==2){
			if(c1==30){
				b1++;
				c1=1;
			}
		}else{
			if(c1==mon[b1]+1){
				b1++;
				c1=1;
			}
		}
		
		if(b1==13){
			b1=1;
			a1++;
		}
		if(a1==9999 && b1==12 && c1==31){
			flag=1;
		}
		sum += get(a1,b1,c1);
//		if(a1==9996 && b1==2){
//			cout << a1 << " " << b1 << " " << c1 << endl;
//			cout << sum << endl;
//		}
		ans[a1][b1][c1] = sum;
		c1++;
//		cout << sum << endl;
	}
	ans[10000][1][1] = ans[9999][12][31];
	while(n--){
		int a,b,c,d,e,f;
		scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
//		f++;
		if(inye(d) && e==2){
			if(f==30){
				e++;
				f=1;
			}
		}else{
			if(f==mon[e]+1){
				e++;
				f=1;
			}
		}
		
		if(e==13){
			e=1;
			d++;
		}
		
		c--;
		if(inye(a) && b==3){
			if(c==0){
				b=2;
				c=29;
			}
		}else{
			if(c==0){
				b--;
				c=mon[b];
			}
		}
		
		if(b==0){
			a--;
			b=12;     
		}
//		cout << a <<" " << b << " " << c << endl;
//		cout << d <<" " << e << " " << f << endl;
		printf("%lld\n",ans[d][e][f] - ans[a][b][c]);
	}
} 
