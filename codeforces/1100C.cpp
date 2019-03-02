#include<bits/stdc++.h>
using namespace std;
int num[100005];
#define PI 3.14159265
int main()
{
	double n,m;
	cin >> n >> m;
	double angle = 360/n/2;
	double val = PI /180;
	double ans = m * sin(angle*val) /(1-sin(angle*val));
	printf("%.6lf\n",ans);
} 
