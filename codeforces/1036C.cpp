#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
			// 位数        数字        非0数字 
void dfs(int digit,long long number,int time)
{
	v.push_back(number);
	if(digit==18) return;
	dfs(digit+1,number*10,time);
	if(time<3){
		for(int i=1;i<=9;i++){
			dfs(digit+1,number*10+i,time+1);	
		}
	}
} 
int main()
{
	int t;
	for(int i=1;i<=9;i++){
		dfs(1,i,1);
	}
	// 记得把1e18也加上 
	v.push_back(1e18);
	sort(v.begin(),v.end());
	cin >> t;
	long long x,y;
	while(t--){
		cin >> x >> y;
				// 因为是闭区间，写法不唯一 
		cout << upper_bound(v.begin(),v.end(),y)-lower_bound(v.begin(),v.end(),x) << endl;
	}
}
 
