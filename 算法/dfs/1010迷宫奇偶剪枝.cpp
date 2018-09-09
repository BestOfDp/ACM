#include<bits/stdc++.h>
using namespace std;
int mat[10][10];
int vis[10][10];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};


int n,m,ti,flag;
int spox,spoy,epox,epoy;

int inborad(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m) return 1;
    else return 0;
}


void dfs(int x,int y,int t)
{
    if(flag) return;
    else if((abs(x-epox)+abs(y-epoy))%2 != (abs(ti-t)%2)) return; 
    else if(x==epox && y==epoy)
    {
        if(t==ti) {flag=1;return;}
    //    else printf("NO\n");
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            int a=x+dir[i][0];
            int b=y+dir[i][1];
            if(inborad(a,b)==1 && vis[a][b]==0 && mat[a][b]!=1)
            {
                vis[a][b]=1;
                dfs(a,b,t+1);
                vis[a][b]=0;
                if(flag) return;
            }
        }
    }
}

int main()
{
    char s[20];
    while(scanf("%d %d %d",&n,&m,&ti)!=EOF)
    {
        if(n==0 && m==0 && ti==0) break;
        flag=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<m;j++)
            {
                if(s[j]=='S')
                {
                    spox=i;
                    spoy=j;
                    mat[i][j]=0;
                    vis[i][j]=1;    
                }    
                else if(s[j]=='D')
                {
                    epox=i;
                    epoy=j;
                    mat[i][j]=0;    
                }
                else if(s[j]=='X') mat[i][j]=1;
                else if(s[j]=='.') mat[i][j]=0;
            } 
        }
        if((abs(spox-epox)+abs(spoy-epoy))%2 != (ti%2)) //¼ôÖ¦ 
        {
            printf("NO\n");
        }
        else 
        {
            dfs(spox,spoy,0);
            if(flag) printf("YES\n");
            else printf("NO\n");    
        }
    }    
}
