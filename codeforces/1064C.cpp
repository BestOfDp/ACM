#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
	int n;
	cin >> n;
	scanf("%s",&s);
	sort(s,s+n);
	printf("%s",s);
}
