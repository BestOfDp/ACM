#include<bits/stdc++.h>
using namespace std;
int t[1005];
int main()
{
	int n,m;
	cin >> n >> m;
	int min1 = 1e9;
	int index=-1;
	int a,b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		if(m<=a){
			t[i] = a;
		}else{
			t[i] = a + ceil((m-a)/b)*b;
			if(t[i] - m) t[i] += b;
		}
	}
	for(int i=0;i<n;i++){
		int dis = t[i] - m;
//		cout << dis << endl;
		if(dis<=min1){
			min1 = dis;
			index = i+1;
		}
	}
	cout << index << endl;
}

