#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL pows(LL n){
	LL t = n;
	LL ans = 1;
	while(t){
		if(t&1)
			ans = ans * n % 7;
		n = n * n % 7;
		t >>= 1;
	}
	return ans;
}

char days[100][100] = {
	"Saturday",
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday"
};

char s[500] = "154145560460660201600156306601465660245066043034456356556160566045265560354556134655632623345245445056455634154456243445023544521512234134334645344523043345132334612433410401123023223534233412632234021223501322306360012612112423122301521123610112460211265256601501001312011260410012506001356100";
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		LL ans = n%294;
		
		printf("%s\n",days[s[((ans-1)+294) % 294]-'0']);
	}
}
