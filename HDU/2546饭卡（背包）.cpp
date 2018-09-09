#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1010;
int val[maxn];
int dp[maxn];

int main(){
    int n,i,j,money;
    while(~scanf("%d",&n)&&n){
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;++i)
            scanf("%d",val+i);
        scanf("%d",&money);
        
        if(money<5){//低于5元直接输出 
            printf("%d\n",money);
            continue;
        }
        
        sort(val,val+n);
        int Max=val[n-1];
        money-=5;//用5元来买最贵的东西
        
        if(money>=val[0]){//如果剩下的钱 连最便宜的物品都买不起，那就不进行操作 
            for(i=0;i<n-1;++i){//i<n-1 因为最贵的东西 已经买走 
                for(j=money;j>=val[i];--j){
                    dp[j]=max(dp[j],dp[j-val[i]]+val[i]);//状态转移方程 
                } 
            } 
        }
        printf("%d\n",money+5-dp[money]-Max);
    }
    return 0;
}
