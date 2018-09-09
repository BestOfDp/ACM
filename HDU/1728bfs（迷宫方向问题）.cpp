#include<iostream>
#include<queue>
using namespace std;

const int m=100+30;
const int INT=1000;



char map[m][m];  //地图
int vis[m][m];  //存储每一个点的最少转弯数

int nn[4][2]={0,1,-1,0,0,-1,1,0};   //方向向量：左，上，右，下


bool outside(int h,int z,int n,int m) //判断是否出界
{
    if(h>0&&h<=n&&z>0&&z<=m)
        return 1;
    else
        return 0;
}

struct node
{
    int c,d;
    int step;       //转弯数
    int direction;  //点的方向
};


int main()
{
    queue<struct node>q;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int i,j;
        for(i=1;i<=n;i++)    //输入迷宫
        {
            for(j=1;j<=m;j++)
            {
                cin>>map[i][j];
            }
        }

        for(i=1;i<110;i++)   //初始化每个节点的转弯数为一个很相当大的值
        {
            for(j=1;j<110;j++)
            {
                vis[i][j]=INT;
            }
        }

        struct node temp;
        int step,a,b;
        cin>>step>>temp.d>>temp.c>>b>>a; //此题很炕人，必须注意坐标的输入循序为:y1,x1,y2,x2
        temp.direction=-1;               //A(temp.c,temp.d)->B(a,b)
        temp.step=0;
        vis[temp.c][temp.d]=temp.step;
        q.push(temp);

        int h,z;
        int foat=0;
        while(!q.empty())
        {
            for(i=0;i<4;i++)
            {
                h=q.front().c + nn[i][0];
                z=q.front().d + nn[i][1];
                if(map[h][z]!='*'&&outside(h,z,n,m))//判断是否障碍，是否出界
                {
                    temp.c=h;
                    temp.d=z;
                    if(q.front().direction==-1)   //判断是否为原点，无论转何方方向数不须加1
                        temp.direction=i;
                    else
                        if(q.front().direction!=i)//不同向
                        {
                            temp.direction=i;
                            temp.step=q.front().step+1;
                        }
                        else                      //同向
                        {
                            temp.direction=q.front().direction;
                            temp.step=q.front().step;
                        }

                        if(temp.c==a&&temp.d==b&&step>=temp.step)//满足条件跳出循环
                        {
                            foat=1;
                            break;
                        }

                        if(vis[temp.c][temp.d]>=temp.step)//若当前点的转弯数小于等于原来的转弯数，
                        {                                //更新当前点的转弯数，并且进队列。
                            vis[temp.c][temp.d]=temp.step;
                            q.push(temp);
                        }
                }
            }
            if(foat) break;
            q.pop();
        }
        if(foat)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        while(!q.empty())
            q.pop();
    }
    return 0;
}

