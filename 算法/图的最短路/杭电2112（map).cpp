#include<bits/stdc++.h> 
#define INF 0x3f3f3f3f
using namespace std; 

int mat[200][200];
int dis[200];
int vis[200];
int main()
{
	int n;
	char s[1001],s1[1001];
	char spos[1000],epos[1000];
	map<string,int>q;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		memset(mat,INF,sizeof(mat));
		q.clear();
		scanf("%s %s",spos,epos);
		q[spos]=1;
		q[epos]=2;
		int t=3;
		int w;
 		for(int i=0;i<n;i++)  
        {  
              
            scanf("%s%s%d",s,s1,&w);  
            if(!q[s])  
            q[s]=t++;  
            if(!q[s1])  
            q[s1]=t++;  
            if(mat[q[s]][q[s1]]>w)   
            mat[q[s]][q[s1]]=mat[q[s1]][q[s]]=w;  
        }  
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=t;i++)	dis[i]=mat[1][i];	
		dis[1]=0;
		vis[1]=1;
		
		for(int i=1;i<=t;i++)
		{
			int mi=INF,pos=-1;
			for(int j=1;j<=t;j++)
			{
				if(mi>dis[j] && !vis[j])
				{
					mi=dis[j];
					pos=j;
				}
			}
				if(pos==-1) break;
				vis[pos]=1;
				for(int j=1;j<=t;j++)
				{
					if(dis[j]>dis[pos] + mat[pos][j] && !vis[j])
					dis[j]=dis[pos]+mat[pos][j];
				}
		}
		if(strcmp(spos,epos)==0)
		{
			printf("0\n");
			continue;
		}
		if(dis[2]==INF) printf("-1\n");
		else printf("%d\n",dis[2]);
	}
}
