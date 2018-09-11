#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2;
int main()
{
	int n;
	cin >> n;
	int a;
	for(int i=0;i<n;i++) 
	{
		cin >> a;
		v1.push_back(a);
	}
	for(int i=0;i<n;i++) 
	{
		cin >> a;
		v2.push_back(a);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	long long sum1 =0,sum2=0;
	for(int i=0;i<2*n;i++)
	{
		int x,y;
		if(v1.size()==0) x=0;
		else x = v1[v1.size()-1];
		if(v2.size()==0) y=0;
		else y = v2[v2.size()-1];
		if(i%2==0){
			if(x>=y){
				sum1+=x;
				v1.pop_back();
			}else{
				v2.pop_back();
			}
		}else{
			if(y>=x){
				sum2+=y;
				v2.pop_back();
			}else{
				v1.pop_back();
			}
		}
	}
	cout << sum1 - sum2 << endl;
}
