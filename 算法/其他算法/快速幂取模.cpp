#include<stdio.h>

//a �� b �η� �� c ȡģ 
int PowerMod(int a,int b,int c)
{
	int ans = 1;
	a = a%c;
	while(b>0)
	{
		if(b%2==1) ans = (ans *a)%c;
		b/=2;
		a=(a*a)%c;
	} 
	return ans;
}
int main()
{
	printf("%d\n",PowerMod(15,5945,100));
} 
