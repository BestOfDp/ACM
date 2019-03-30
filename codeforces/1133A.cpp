#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	scanf("%d:%d",&a,&b);
	scanf("%d:%d",&c,&d);
	int dis = 60*(c-a) + (d-b);
	dis /= 2;
	int h = a + (dis/60);
	dis %= 60;
	int m = b + dis;
	h += m/60;
	m %=60;
	printf("%.2d:%.2d\n",h,m);
} 
