#include<bits/stdc++.h>
#define INF 99999999
using namespace std;
int main()
{
	int n,m;
	int u[8],v[8],w[8]; // u ----> v �� distance  w
	int first[6],next[8]; // first��n��1    !!!! next��m��1
	int dis[6],vis[8]; //book��¼��Щ�����Ѿ��ڶ����� 
	
	int  que[101]={0},head=1,tail=1; //����һ������ 
	
	scanf("%d%d",&n,&m); // ������ ����
	
	for(int i=1;i<=n;i++) dis[i]=INF;  //��ʼ��dis���� 
	dis[1]=0;
	
	for(int i=1;i<=n;i++) vis[i]=0; //��ʼ�� ��ʾһ��ʼ�����ڶ����� 
	
	for(int i=1;i<=n;i++) first[i]=-1; //��ʾ 1��n һ��ʼ��ʱû�б�
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		//���������ǽ����ڽӱ�Ĺؼ� 
		next[i]=first[u[i]];
		first[u[i]]=i;
	} 
	
	//1�Ŷ������
	que[tail]=1;
	tail++;
	vis[1]=1; //���1�Ŷ����Ѿ����
	
	int k;
	while(head < tail ) // ���в�Ϊ�յ�ʱ��ѭ��
	{
		k=first[que[head]]; //��Ҫ����Ķ��� ��ʵ���� ���е�ͷ
		while(k!=-1)//ɨ�赱ǰ�������еı� 
		{
			if(dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]]+w[k];
			
				if(vis[v[k]]==0)
				{
					que[tail]=v[k];
					tail++;
					vis[v[k]]=1;
				}
			}
			k=next[k];
		}
		//����
		vis[que[head]]=0;
		head++; 
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
	 
}
