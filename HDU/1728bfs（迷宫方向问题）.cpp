#include<iostream>
#include<queue>
using namespace std;

const int m=100+30;
const int INT=1000;



char map[m][m];  //��ͼ
int vis[m][m];  //�洢ÿһ���������ת����

int nn[4][2]={0,1,-1,0,0,-1,1,0};   //�������������ϣ��ң���


bool outside(int h,int z,int n,int m) //�ж��Ƿ����
{
    if(h>0&&h<=n&&z>0&&z<=m)
        return 1;
    else
        return 0;
}

struct node
{
    int c,d;
    int step;       //ת����
    int direction;  //��ķ���
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
        for(i=1;i<=n;i++)    //�����Թ�
        {
            for(j=1;j<=m;j++)
            {
                cin>>map[i][j];
            }
        }

        for(i=1;i<110;i++)   //��ʼ��ÿ���ڵ��ת����Ϊһ�����൱���ֵ
        {
            for(j=1;j<110;j++)
            {
                vis[i][j]=INT;
            }
        }

        struct node temp;
        int step,a,b;
        cin>>step>>temp.d>>temp.c>>b>>a; //����ܿ��ˣ�����ע�����������ѭ��Ϊ:y1,x1,y2,x2
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
                if(map[h][z]!='*'&&outside(h,z,n,m))//�ж��Ƿ��ϰ����Ƿ����
                {
                    temp.c=h;
                    temp.d=z;
                    if(q.front().direction==-1)   //�ж��Ƿ�Ϊԭ�㣬����ת�η������������1
                        temp.direction=i;
                    else
                        if(q.front().direction!=i)//��ͬ��
                        {
                            temp.direction=i;
                            temp.step=q.front().step+1;
                        }
                        else                      //ͬ��
                        {
                            temp.direction=q.front().direction;
                            temp.step=q.front().step;
                        }

                        if(temp.c==a&&temp.d==b&&step>=temp.step)//������������ѭ��
                        {
                            foat=1;
                            break;
                        }

                        if(vis[temp.c][temp.d]>=temp.step)//����ǰ���ת����С�ڵ���ԭ����ת������
                        {                                //���µ�ǰ���ת���������ҽ����С�
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

