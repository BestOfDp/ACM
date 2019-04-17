#include<stdio.h>
int n;
struct tree{
    int l,r,m,v;
}t[400010];
void pushdown(int k){//向下传递，但是并不是加上而是直接改变当前的值
    if(t[k].m){
        t[k*2].m=t[k].m;
        t[k*2].v=(t[k*2].r-t[k*2].l+1)*t[k].m;
        t[k*2+1].m=t[k].m;
        t[k*2+1].v=(t[k*2+1].r-t[k*2+1].l+1)*t[k].m;
        t[k].m=0;
    }
}
void pushup(int k){//向上传递
    t[k].v=t[k*2].v+t[k*2+1].v;
}
void build(int k,int l,int r){//构建线段树
    t[k].l=l,t[k].r=r,t[k].m=0;
    if(t[k].r==t[k].l){
        t[k].v=1;
        return ;
    }
    int mid=(l+r)/2;
    if(mid<l)  build(k*2+1,l,r);
    else if(mid>=r)  build(k*2,l,r);
    else{
        build(k*2,l,mid);
        build(k*2+1,mid+1,r);
    }
}
int query(int k,int l,int r){//查询线段树区间
    if(t[k].l>=l&&t[k].r<=r) return t[k].v;
    int mid=(t[k].r+t[k].l)/2;
    if(mid<l)  return query(k*2+1,l,r);
    else if(mid>=r)  return query(k*2,l,r);
    else return query(k*2,l,mid)+query(k*2+1,mid+1,r);
}
void updata(int k,int l,int r,int add){//更新线段树区间
    if(t[k].l>=l&&t[k].r<=r){
        t[k].m=add;
        t[k].v=add*(t[k].r-t[k].l+1);
        return ;
    }
    pushdown(k);
    int mid=(t[k].r+t[k].l)/2;
    if(mid<l) updata(k*2+1,l,r,add);
    else if(mid>=r)  updata(k*2,l,r,add);
    else{
        updata(k*2,l,mid,add);
        updata(k*2+1,mid+1,r,add);
    }
    pushup(k);
}
int main(){
    int m,ca,num=1;
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&n,&ca);
        build(1,1,n);
        while(ca--){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            updata(1,l,r,x);
        }
        printf("Case %d: The total value of the hook is %d.\n",num++,query(1,1,n));
    }
    return 0;
}
