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
    tree[rt] = tree[rt*2] + tree[rt*2+1]; ///区间和的更新操作
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
    // l,r 代表的是这个区间内的左端点 和 右端点， rt代表的是 [l,r] 这个区间内的值是存在哪一个位置的。
    if(l==r){
        //scanf("%d",&tree[rt]);
         tree[rt] = a[l];
        return;
    }
    int m=(l+r)/2;// 对于区间区分，我们一般将m点划入左半边区间
    Build(l,m,rt*2);
    Build(m+1,r,rt*2+1);
    PushUp(rt); // PushUp 函数是通过2个子节点来更新现在这个节点的状态， 对于不同的要求需要不同的写法。
 
}
long long Query(int l,int r,int rt,int L,int R){// [L,R]为查询区间
    if(L<=l&&r<=R){
        return tree[rt];// 如果成立则满足查询区间覆盖了当前区间， 直接返回当前区间的值
    }
    int m=(l+r)/2;
    long long  res=0;
    PushDown(rt, m-l+1, r-m);
    if(L<=m)    res+=Query(l,m,rt*2,L,R);//左边有一部分需要查询的区域。
    if(m<R)     res+=Query(m+1,r,rt*2+1,L,R);//右边有一部分。
    return res;
 
}
 
 
 
void Updata(int l,int r,int rt,int L,int R,int C){// l,r,rt 与前面的定义一样， L代表的是要更新区间的位置，C代表的是修改后的值
    if(L <= l && r <= R){// 这里不能写成 if(l == L) 因为有可能左端点恰好是要更新的位置， 但是还有右端点， 我们直接更新的只有区间 [L,L]。
        tree[rt] += (long long)C*(r-l+1);
        lazy[rt] += C;
 
        return ;
    }
    int m=(l+r)/2;
    PushDown(rt, m-l+1, r-m);
    if(L<=m) Updata(l,m,rt*2,L,R,C);//要更新的区间在左边部分，所以往左边走，更新左边
    if(m < R) Updata(m+1,r,rt*2+1,L,R,C);//要更新的区间在右边部分， 往右边走，更新右边
    PushUp(rt);//更新完子节点之后需要更新现在的位置， 需要保证线段树的性质。
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
