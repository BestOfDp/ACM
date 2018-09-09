#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct stu
{
	int sum;
	char name[23];
}students[1000];

bool complare(stu a,stu b)
{
	if(a.sum==b.sum)
	{
		if(strcmp(a.name,b.name)>0)
		{
			return a.name<b.name;
		}
	}
	else
	{
	     return a.sum>b.sum;	
	}
}

int main()
{
	int a,b,c,d,e;
	int i,j;
	int score[11]={0};
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		int count=0;
		scanf("%d %d",&b,&c);
		for(i=0;i<b;i++)
		{
			scanf("%d",&score[i]);
		}
		for(i=0;i<a;i++)
		{
			students[i].sum=0;
			scanf("%s",&students[i].name);
			scanf("%d",&d);
			for(j=0;j<d;j++)
			{
				scanf("%d",&e);
				students[i].sum+=score[e-1];
			}
			if(students[i].sum>=c)
			{
				count++;
			}
		}
		printf("%d\n",count);	
		sort(students,students+a,complare);
		for(i=0;i<count;i++)
		{
			printf("%s %d\n",students[i].name,students[i].sum);
		}
	}
}
