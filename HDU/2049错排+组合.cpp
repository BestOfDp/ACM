#include<stdio.h>
 __int64 C(int n,int m)
 {
 	int i;
 	__int64 s1=1,s2=1;
 	for(i=1;i<=m;i++)
 	{
 		s1*=(n-i+1);
 		s2*=i;
	 }
	 return s1/s2;
 }
int main()
{
	int t;
	int n,m;
	int i;
	__int64 s;
	__int64 a[22]={0,0,1,2};
	for(i=4;i<=20;i++)
   	{
        a[i]=(i-1)*(a[i-1]+a[i-2]); //´íÅÅ¹«Ê½ 
    }
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		s=a[m]*C(n,n-m);
    	printf("%I64d\n",s);
	}
 } 
