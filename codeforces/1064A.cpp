#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
	for(int i=0;i<3;i++) cin >> a[i];
	sort(a,a+3);
	if(a[0]+a[1] > a[2] )cout << 0 << endl;
	else cout << a[2]-(a[0]+a[1])+1 << endl;
} 
