#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >>f;
		if(a>d){
			cout << "cpcs" << endl;
			continue;
		}else if(a<d){
			cout << "javaman" << endl;
			continue;
		}
		
		if(b>e){
			cout << "cpcs" << endl;
			continue;
		}else if(b<e){
			cout << "javaman" << endl;
			continue;
		}
		
		if(c>f){
			cout << "cpcs" << endl;
			continue;
		}else if(c<f){
			cout << "javaman" << endl;
			continue;
		}
		cout << "same" << endl;
	}
}
