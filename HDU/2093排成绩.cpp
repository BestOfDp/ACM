#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct stu
{
	char name[11];
	int  num;
	int scores;
	char s[13][10];
}students[1001];

bool complare(stu a,stu b)
{
	if(a.num==b.num)
	{
		if(a.scores==b.scores)
		{
			if(strcmp(a.name,b.name)>0)
			{
				return 0;
			}
			else return 1;
		}
		else return a.scores<b.scores;
	}
	else
	{
		return a.num>b.num;	
	}
}

int main()
{
	int n,n1,i,j;
	scanf("%d %d",&n,&n1);
	int index=0;
	while(scanf("%s",students[index].name)!=EOF)
	{
		students[index].num=0;
		students[index].scores=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",students[index].s[i]);
		}
		for(i=0;i<n;i++)
		{
			int num1=0;
			int index1=0;
			//算正确的个数 
			if(students[index].s[i][0]!='-' && students[index].s[i][0]!='0')
			{
				students[index].num++;
			}
			//算做出题目的分数 
			/*if(students[index].s[i][0]=='-') 
			{
			for(j=strlen(students[index].s[i])-1;j>0;j--)
			{
				num1+=((students[index].s[i][j]-'0')*pow(10,index1++));
			}
			students[index].scores+=(n1*num1);
			}*/
			if(students[index].s[i][0]!='0' && students[index].s[i][0]!='-')
			{
				int k=strlen(students[index].s[i]);
				if(students[index].s[i][k-1]==')')
				{
					for(j=k-2;students[index].s[i][j]!='(';j--)
					{
						num1+=((students[index].s[i][j]-'0')*pow(10,index1++));
					}
					students[index].scores+=(n1*num1);
					int t=k-1-2-index1;
					index1=0;
					num1=0;
					for(j=t;j>=0;j--)
					{
						num1+=((students[index].s[i][j]-'0')*pow(10,index1++));
					}
					students[index].scores+=(num1);
				}
				else
				{
					for(j=k-1;j>=0;j--)
					{
						num1+=((students[index].s[i][j]-'0')*pow(10,index1++));
					}
					students[index].scores+=num1;
				}
			}	
		}
		index++;
	}
	sort(students,students+n,complare);
	for(i=0;i<index;i++)
	{
		printf("%-10s %2d %4d\n",students[i].name,students[i].num,students[i].scores);
	}
 } 
 /*
 8 20 
 Smith -1 -16 8 0 0 120 39 0
 John 116 -2 79 0 0 82 55(1) 0
 Josephus 72(3) 126 10 -3 0 47 21(2) -2
 Bo 0 0 -8 0 0 0 0 0
 Alice -2 67(2) 13 -1 0 133 79(1) -1
 Bob 0 0 57(5) 0 0 168 -7 0
 */
