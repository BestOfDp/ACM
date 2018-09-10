#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f[20000]={2};
	int k=1;
	for(int i=3;i<45000;i++)
	{
		int q=1;
		for(int j=0;j<k;j++)
		{
			if(i%f[j]==0){q=0;break;}	
		}
		if(q) f[k++]=i;	
		//if(i%1000==0)printf("%d\n",i);
	}
	int n;
	cin >> n;
	if(n==1){
		cout << "No" << endl;
		return 0;
	}
	if(n%4==0 || n%4==3){
		cout << "Yes" << endl;
		cout << "1 2" << endl;
		cout << n-1;
		for(int i=1;i<=n;i++){
			if(i!=2) cout << " " << i;
		}
		cout << endl;
	}else{
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
		}
		int index=0;
		while(f[index]<sum){
			if(sum%f[index]==0){
				cout << "Yes" << endl;
				cout << 1 << " " << f[index] << endl;
				cout << n-1 ;
				for(int i=1;i<=n;i++){
					if(i!=f[index]) cout << " " << i;
				}
				cout << endl;
				return 0;
			}else index++;
		}
		cout << "No" << endl;
	}
}
 
