 #include<bits/stdc++.h>
 using namespace std;
 int a[100005];
 int dis[100005];
 int cmp(int a,int b){
 	return a>b;
 }
 int main()
 {
	int n,m,k;
	cin >> n >> m >> k; 	
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=1;i<n;i++) dis[i-1] = a[i]-a[i-1];
	sort(dis,dis+n-1,cmp);
	int ans = a[n-1] - a[0] + 1;
	for(int i=0;i<k-1;i++){
		ans -= dis[i]-1;
	} 
	cout << ans << endl;
} 
