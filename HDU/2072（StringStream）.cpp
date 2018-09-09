#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,buf;
	while(getline(cin,s))
	{
		if(s[0]=='#') break;
		set<string> dict;
		stringstream ss(s);
		while(ss>>buf)
		{
			dict.insert(buf);
		}
		printf("%d\n",dict.size());
	}
}
