#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

string a;
string b;
bool ispe();
bool isdel(char ch);

int main()
{
	int t;
	scanf("%d",&t);
	string s;
	getchar();
	while(t--)
	{
		a.clear();
		b.clear();
		while(getline(cin,s) && s!="START");
		while(getline(cin,s))
		{
			if(s =="END") break;
			a += s;
			a += '\n';
		}
		
		while(getline(cin,s) && s!="START");
		while(getline(cin,s))
		{
			if(s=="END") break;
			b += s;
			b += '\n';
		}
		if(a.length() == b.length() && a==b)
		{
			printf("Accepted\n");
			continue;
		}
		if(ispe())
			cout << "Presentation Error" << endl;
		else
			cout << "Wrong Answer" << endl;
	}	
}

bool ispe()
{
	string aj,bj;
	for(int i=0;i<a.length();i++)
	{
		if(isdel(a[i])) aj+=a[i];
	}
	
	for(int i=0;i<b.length();i++)
	{
		if(isdel(b[i])) bj+=b[i];
	}
	
	if(aj==bj) return true;
	else return false;
}

bool isdel (char ch)
{
	if(ch!=' ' && ch!='\t' && ch!='\n') return true;
	else return false;
}

