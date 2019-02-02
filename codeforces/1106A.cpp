#include<bits/stdc++.h>
int n;
char s[600][600];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int ans=0;
	for (int i=2;i<n;i++)
		for (int j=2;j<n;j++){
			if (s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i][j]=='X')++ans;
		}
	printf("%d",ans);
	return 0;
}
