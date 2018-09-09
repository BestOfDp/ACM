#include<bits/stdc++.h>
using namespace std;

double exp()
{
	char s[101];
	scanf("%s",s);
	switch(s[0])
	{
		case '*': return exp()*exp();break;
		case '+': return exp()+exp();break;
		case '-': return exp()-exp();break;
		case '/': return exp()/exp();break;
		default : return atof(s); 
	}
}
int main()
{
	printf("%lf\n",exp());
}
