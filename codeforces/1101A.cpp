#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		int number_a = (a-1) / c;
		
		if(number_a >=1){
			cout << c  << endl;
		}else{
			cout << c * ((b/c)+1) << endl;
		}
	}
 } 
