#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void turn(int n,int r)
{
    int j,k;
    int a[100];
    int add=0;
    if(n<0)
    {
        add=n;
        n=-n;
    }
    int i=0;
    do
    {
        a[i]=n%r;
        n=n/r;
        i++;
    }while(n!= 0);
    if(i>7)printf("%7s\n","ERROR");
    else
    {
    	if(add<0)
   	 	{
        	printf("-");
   	 	}
   	 	for(k=0;k<7-i;k++)
   	 	{
   	 		printf(" ");
			}
    	for(j=i-1;j>=0;j--)
    	{
        	if(a[j]>=0 && a[j]<=9)
        	{
           	 	printf("%d",a[j]);    
        	}
        	else
        	{
            	switch(a[j])
            	{
                	case 10:printf("A");break;
                	case 11:printf("B");break;
                	case 12:printf("C");break;
                	case 13:printf("D");break;
                	case 14:printf("E");break;
                	case 15:printf("F");break;
            	}
        	}
    	}
    	printf("\n");
	}
  }

int main()
{
	char s[101];
	int a,b,i;
	while(scanf("%s %d %d",&s,&a,&b)!=EOF)
	{
		int sum=0;
		int len=strlen(s);
		int index=0;
		for(i=len-1;i>=0;i--)
		{
			if(s[i]=='A') sum+=(int)(10)*pow(a,index++);
			else if(s[i]=='B') sum+=(int)(11)*pow(a,index++);
			else if(s[i]=='C') sum+=(int)(12)*pow(a,index++);
			else if(s[i]=='D') sum+=(int)(13)*pow(a,index++);
			else if(s[i]=='E') sum+=(int)(14)*pow(a,index++);
			else if(s[i]=='F') sum+=(int)(15)*pow(a,index++);
			else sum+=(int)(s[i]-'0')*pow(a,index++);
		}
		turn(sum,b);
	}
}
