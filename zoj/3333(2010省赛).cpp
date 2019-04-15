#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int dis1 = abs(a-b);
		int dis2 = abs(a-c);
		if(dis1<dis2){
			cout << "A" << endl;
		}else cout << "B" << endl;
	}
}
