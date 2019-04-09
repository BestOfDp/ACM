#include<iostream>
using namespace std;
int a[1000005];
int main()
{
	int t;
	cin >> t;
	while(t--){
		int l,n;
		cin >> l >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		
		int min1 = 0;
		for(int i=0;i<n;i++){
			min1 = max(min(l-a[i],a[i]),min1);
		} 
		
		int max1 = 0;
		for(int i=0;i<n;i++){
			max1 = max(max(l-a[i],a[i]),max1);
		} 
		cout << min1 << " " << max1 << endl;
	}	
} 
