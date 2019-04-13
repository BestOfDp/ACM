#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,k;
#define INF 0x3f3f3f3f
double a[10005];
int bin(double d){
	int sum=0;
	for(int i=0;i<n;i++){
		sum += (a[i]/d);
	}
	return sum >= k;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%lf",&a[i]);
	double l=0,r=INF;
	for(int i=0;i<100;i++){
		double mid = (l+r)/2;
		if(bin(mid)) l = mid;
		else r = mid;
	}
	printf("%.2lf\n",floor(r * 100)/100);
} 
