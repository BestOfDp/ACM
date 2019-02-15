#include<bits/stdc++.h>
using namespace std;
const double eps = 1.0e-6; //¸¡µã
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
  __int64 x,y,l;
}po[200005];

int cmp2(node a,node b)
{
	return a.x < b.x;
}


int main()
{
	string s,t;
	cin >> s >>t;
	int a[27],b[27];	
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++)
	{
		a[s[i]-'a']++;
	} 
	for(int i=0;i<t.size();i++)
	{
		a[t[i]-'a']--;
	} 
	for(int i=0;i<26;i++)
	{
		if(a[i]<0)
		{
			cout << "need tree" <<endl;
			return 0;
		}
	}
	if(s.size()==t.size())
	{
		cout << "array" <<endl;
	}
	else
	{
		int flag=1;
		int ff=-1;
		int cnt=0;
		for(int i=0;i<t.size();i++)
		{
			for(int j=ff+1;j<s.size();j++)
			{
				if(t[i]==s[j])
				{
					ff=j;
					cnt++;
					break;
				}
			}
		} 
		if(cnt==t.size())
		{
			cout << "automaton" <<endl;
		}
		else cout << "both" <<endl;
	}
}
