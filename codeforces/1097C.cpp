#include<bits/stdc++.h>
using namespace std;
string s;
stack<char>temp;
int ans;
// l,r代表( )个数，ansl,ansr 代表 “情况”的个数 
int l[500005],ansl[500005];
int r[500005],ansr[500005];
void getString(int index){
	while(!temp.empty()) temp.pop();
	for(int i=0;i<s.size();i++){ 
		if(s[i]=='('){
			temp.push(s[i]);
			l[index]++;
		}
		else{
			if(temp.empty()){
				temp.push(s[i]);
				r[index]++;
				continue;
			}
			if(temp.top()=='(') {
				temp.pop();
				l[index]--;		
			}
			else{
				temp.push(s[i]);
				r[index]++;	
			}
		}
	} 
	if(l[index]==r[index] && temp.empty()){
		ans++;
	}else {
		if(r[index]==0 && l[index]!=0){
			ansl[l[index]]++;
		}else if(r[index]!=0 && l[index]==0){
			ansr[r[index]]++;
		}
	} 	
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		getString(i);
	}
	ans /= 2;
	for(int i=1;i<500005;i++){
		ans += min(ansl[i],ansr[i]);
	}
	cout << ans << endl;
} 
