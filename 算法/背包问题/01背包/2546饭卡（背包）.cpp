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
        
        if(money<5){//����5Ԫֱ����� 
            printf("%d\n",money);
            continue;
        }
        
        sort(val,val+n);
        int Max=val[n-1];
        money-=5;//��5Ԫ�������Ķ���
        
        if(money>=val[0]){//���ʣ�µ�Ǯ ������˵���Ʒ�������ǾͲ����в��� 
            for(i=0;i<n-1;++i){//i<n-1 ��Ϊ���Ķ��� �Ѿ����� 
                for(j=money;j>=val[i];--j){
                    dp[j]=max(dp[j],dp[j-val[i]]+val[i]);//״̬ת�Ʒ��� 
                } 
            } 
        }
        printf("%d\n",money+5-dp[money]-Max);
    }
    return 0;
}
