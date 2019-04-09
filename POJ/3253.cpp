#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<long long,vector<long long>,greater<long long> > q;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		q.push(temp);
	}
	long long ans=0;
	while(q.size()!=1){
		long long min1 = q.top();
		q.pop();
		long long min2 = q.top();
		q.pop();
		ans += min1+min2;
		q.push(min1+min2);
	}
	cout << ans <<endl;
}
