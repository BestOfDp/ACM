#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		int ans=0;
		string temp=s;
		while(temp.find("cat")!=string::npos){
			temp = temp.substr(temp.find("cat")+3,temp.size());
//			cout << temp << endl;
			ans++;
		} 
		temp =s;
		while(temp.find("dog")!=string::npos){
			temp = temp.substr(temp.find("dog")+3,temp.size());
			ans++;
		} 
		cout << ans << endl;
	}
} 
