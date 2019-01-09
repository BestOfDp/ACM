#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>temp;
int ans;
// l,r代表( )个数，ansl,ansr 代表 “情况”的个数 
int l[500005],ansl[500005];
int r[500005],ansr[500005];
void getString(int index){
	temp.clear();
	for(int i=0;i<s.size();i++){ 
		if(s[i]=='('){
			temp.push_back(s[i]);
			l[index]++;
		}
		else{
			if(temp.size()==0){
				temp.push_back(s[i]);
				r[index]++;
				continue;
			}
			if(temp[temp.size()-1]=='(') {
				temp.pop_back();
				l[index]--;		
			}
			else{
				temp.push_back(s[i]);
				r[index]++;	
			}
		}
	} 
	if(l[index]==r[index] && temp.size()==0){
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
