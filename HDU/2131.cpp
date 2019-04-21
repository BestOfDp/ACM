#include<bits/stdc++.h>
using namespace std;
char s[500];
int main(){
	char c;
	while(scanf("%c %s",&c,s)!=EOF){
		int cnt=0;
		if(c>='A' && c<='Z') c+='a'-'A';
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='A' && s[i]<='Z') s[i]+='a'-'A';
//			cout << s[i] << endl;
			if(s[i]==c){
				cnt++;
			}
		}
		getchar();
		printf("%.5lf\n",(double)((double)cnt /strlen(s) ));
	}
}
