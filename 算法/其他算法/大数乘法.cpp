#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int MAX=10000;
using namespace std;

void Multi(char str1[],char str2[])
{
	int len1,len2,i,j;
	int a[MAX+10],b[MAX+10],c[MAX*2+1];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	len1=strlen(str1);
	for(j=0,i=len1-1;i>=0;i--) //�����ֵ�����
	{
		a[j++]=str1[i]-'0';	
	} 
	
	len2=strlen(str2);
	for(j=0,i=len2-1;i>=0;i--) //�����ֵ�����
	{
		b[j++]=str2[i]-'0';	
	} 
	
	for(i=0;i<len2;i++) //�õڶ��������Ե�һ������ÿ��һλ�ȳ�����������ͳһ��һλ
	{
		for(j=0;j<len1;j++)
		{
			c[i+j]+=b[i]*a[j];
		}
	}
	 
	for(i=0;i<MAX*2;i++) //ѭ��ͳһ�����λ����
	{
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;	
		}	
	} 
	
	//���
	for(i=MAX*2;(c[i]==0) && (i>=0) ;i--);
	if(i>=0)
	{
		for(;i>=0;i--)
		{
			printf("%d",c[i]);	
		}	
	}	
	else printf("0");
	printf("\n");
	
}
int main()
{
	char s[125]="125589985565999999999995";
	char s1[154]="848597865455948456489499856154";
 	Multi(s,s1);
}
