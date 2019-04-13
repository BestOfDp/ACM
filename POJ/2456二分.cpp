#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int a[100005]; 
int bin(int dis){
	int number=1;
	int cnt=a[0];
	for(int i=1;i<n;i++){
		if(a[i]-cnt >= dis){
			number++;
			cnt = a[i];
		}
		if(number>=m) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int l=1;
	int r=a[n-1] - a[0];
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(bin(mid)==1) l=mid+1;
		else r=mid;
	}
	printf("%d\n",r-1);
}
