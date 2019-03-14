#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int temp;
	int a[10005];
	for(int i=0;i<n;i++){
		cin >> temp >> a[i];
	}
	int current ;
	cin >> current;
	for(int i=0;i<n;i++){
		if(a[i]>=current){
			cout << n-i << endl;
			return 0;
		}
	}
}
