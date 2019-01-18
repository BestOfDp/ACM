#include<bits/stdc++.h>
using namespace std;
int nextval[200005];
char s[200005];
int dp[200005];
void gen_next(){
	int ll = strlen(s);
	nextval[0]=0;
	nextval[1]=0;
	int k=0; 
	for(int i=1;i<ll;i++){
		while(k>0 && s[k]!=s[i]) k = nextval[k];
		if(s[k]==s[i]) k++;
		nextval[i+1]=k; 
	}
	nextval[0]=-1;
}
 

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int ll ;
		scanf("%d",&ll); 
		memset(nextval,0,sizeof(nextval));
		memset(dp,0,sizeof(dp));
		scanf("%s",s);
		gen_next();
		int sum=0;
		for(int i=1;i<=ll;i++){
			dp[i]=dp[nextval[i]] + 1;
			sum  = (sum + dp[i]+10007) %10007;
		}
		printf("%d\n",sum);
	} 
}
