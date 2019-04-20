#include<bits/stdc++.h>
using namespace std;
int dis(char need,char now){
	if(need > now){
		return min(need - now,now + 26 - need);
	}else{
		return min(now - need,need + 26 - now);
	}
}
int get(string s){
	int ans=0;
	ans += dis('A',s[0]);
	ans += dis('C',s[1]);
	ans += dis('T',s[2]);
	ans += dis('G',s[3]);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int min1 = 1e9;
	for(int i=4;i<=n;i++){
		min1 = min(get(s.substr(i-4,i)),min1);
	}
	cout << min1 << endl;
}
