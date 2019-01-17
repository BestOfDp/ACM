#include<bits/stdc++.h>
using namespace std;
int nextval[100005];
char s[100005];
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
		memset(nextval,0,sizeof(nextval));
		scanf("%s",s);
		int ll = strlen(s);
		gen_next();
		int number = ll - nextval[ll];
		if(number==ll) printf("%d\n",number);
		else if(ll % number ==0) printf("0\n");
		else printf("%d\n",number - ll % number);
	} 
}
