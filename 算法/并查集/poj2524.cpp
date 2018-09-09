#include<iostream>
using namespace std;
int pre[5005];

int find(int x)
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}

void join(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx!=fy) pre[fy]=fx;
}

int main()
{
	int n,m;
	int a,b;
	int index=1;
	while(1)
	{
		scanf("%d %d",&n,&m);
		int cnt=0;
		if(n==-1 && m==-1) break;;
		for(int i=1;i<=5000;i++) pre[i]=i;
		do
		{
			if(n==0 && m==0) break;
			join(n,m);
		}while(scanf("%d%d",&n,&m));
		for(int i=1;i<=5000;i++)
		{
			if(pre[i]==i) cnt++;
		}
		cout << cnt << endl;
	}
}
