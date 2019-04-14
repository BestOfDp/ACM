#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int a[5005];
int num[5005];
int n;
int cal(int k){
	memset(num,0,sizeof(num));
	int ans=0;
	int sum=0;
	for(int i=0;i+k<=n;i++){
		if((a[i]+sum)%2==0){
			ans++;
			num[i]=1;
		}
		sum+=num[i];
		if(i-k+1>=0){
			sum -= num[i-k+1];
		}
	}
	for(int i=n-k+1;i<n;i++){
		if((a[i]+sum)%2==0) return 1e9;
		if(i-k+1>=0){
			sum -= num[i-k+1];
		}
	}
	return ans;
	
}
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		char c;
		scanf("%c",&c);
		if(c=='B') a[i]=0;
		else a[i]=1;
		getchar();	
	}
	int k=0;
	int m=1e9;
	for(int i=1;i<=n;i++){
		int ans = cal(i);
		if(ans < m){
			k = i;
			m = ans;
		}
	}
	printf("%d %d\n",k,m);
} 
