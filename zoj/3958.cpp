#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		long long sum1=0,sum2=0;
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			if(temp==1){
				sum1++;
			}else if(temp==2) sum2++;
		}
		if(sum1 > sum2){
			cout << "Kobayashi" << endl;
		}else if(sum1 < sum2){
			cout << "Tohru" << endl;
		}else cout << "Draw" << endl;
	}
}
