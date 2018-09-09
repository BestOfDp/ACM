#include<iostream>
using namespace std;
int pre[1005],a[1005],b[1005];

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
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		cin >> m;
		int cnt=0;
		for(int i=1;i<=n;i++) pre[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin >> a[i] >> b[i];
			join(a[i],b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(pre[i]==i)
			{
				cnt++;
			}
		}
		cout << cnt-1 << endl;
	}
}
