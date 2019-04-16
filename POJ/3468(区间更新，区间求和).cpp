#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
const int N = 1e5+10;
using namespace std;
int t,n,q;
long long tree[N<<2];
long long lazy[N<<2];
int a[N];
void PushUp(int rt){
    tree[rt] = tree[rt*2] + tree[rt*2+1]; ///����͵ĸ��²���
}
void PushDown(int rt, int llen, int rlen){
    if(lazy[rt]){
        lazy[rt*2] += lazy[rt];
        lazy[rt*2+1] += lazy[rt];
        tree[rt*2] += lazy[rt] * llen;
        tree[rt*2+1] += lazy[rt] * rlen;
        lazy[rt] = 0;
    }
}
void Build(int l,int r,int rt){
    // l,r ���������������ڵ���˵� �� �Ҷ˵㣬 rt������� [l,r] ��������ڵ�ֵ�Ǵ�����һ��λ�õġ�
    if(l==r){
        //scanf("%d",&tree[rt]);
         tree[rt] = a[l];
        return;
    }
    int m=(l+r)/2;// �����������֣�����һ�㽫m�㻮����������
    Build(l,m,rt*2);
    Build(m+1,r,rt*2+1);
    PushUp(rt); // PushUp ������ͨ��2���ӽڵ���������������ڵ��״̬�� ���ڲ�ͬ��Ҫ����Ҫ��ͬ��д����
 
}
long long Query(int l,int r,int rt,int L,int R){// [L,R]Ϊ��ѯ����
    if(L<=l&&r<=R){
        return tree[rt];// ��������������ѯ���串���˵�ǰ���䣬 ֱ�ӷ��ص�ǰ�����ֵ
    }
    int m=(l+r)/2;
    long long  res=0;
    PushDown(rt, m-l+1, r-m);
    if(L<=m)    res+=Query(l,m,rt*2,L,R);//�����һ������Ҫ��ѯ������
    if(m<R)     res+=Query(m+1,r,rt*2+1,L,R);//�ұ���һ���֡�
    return res;
 
}
 
 
 
void Updata(int l,int r,int rt,int L,int R,int C){// l,r,rt ��ǰ��Ķ���һ���� L�������Ҫ���������λ�ã�C��������޸ĺ��ֵ
    if(L <= l && r <= R){// ���ﲻ��д�� if(l == L) ��Ϊ�п�����˵�ǡ����Ҫ���µ�λ�ã� ���ǻ����Ҷ˵㣬 ����ֱ�Ӹ��µ�ֻ������ [L,L]��
        tree[rt] += (long long)C*(r-l+1);
        lazy[rt] += C;
 
        return ;
    }
    int m=(l+r)/2;
    PushDown(rt, m-l+1, r-m);
    if(L<=m) Updata(l,m,rt*2,L,R,C);//Ҫ���µ���������߲��֣�����������ߣ��������
    if(m < R) Updata(m+1,r,rt*2+1,L,R,C);//Ҫ���µ��������ұ߲��֣� ���ұ��ߣ������ұ�
    PushUp(rt);//�������ӽڵ�֮����Ҫ�������ڵ�λ�ã� ��Ҫ��֤�߶��������ʡ�
}
int main()
{
 
   scanf("%d%d",&n,&q);
 
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        Build(1,n,1);
        char tmp[10];
        int a,b,c;
        while(q--){
            scanf("%s",tmp);
 
            if(strcmp(tmp,"C")==0){
                scanf("%d%d%d",&a,&b,&c);
                Updata(1,n,1,a,b,c);
            }
            if(strcmp(tmp,"Q")==0){
                scanf("%d%d",&a,&b);
                printf("%lld\n",Query(1,n,1,a,b));
            }
 
 
        }
    return 0;
}
