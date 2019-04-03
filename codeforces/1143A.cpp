#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int c1=0;
	int c2=0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==0) c1++;
		else c2++;
	}	
	for(int i=0;i<n;i++){
		if(a[i]==0) {
			c1--;	
		}
		else c2--;
		if(c1==0 || c2==0) {
			cout << i + 1 << endl;
			return 0;
		}
	}	
} 
