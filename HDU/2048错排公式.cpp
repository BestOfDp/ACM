#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
    int t;
    int n;
    __int64 a[22]={0,0,1,2};
    double s;
    int i;
    for(i=4;i<=20;i++)
    {
        a[i]=(i-1)*(a[i-1]+a[i-2]); //´íÅÅ¹«Ê½ 
    }
    scanf("%d",&t);
    while(t--)
    {
        s=1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            s*=i;
        }
        
        printf("%.2lf%%\n",double(a[n]/s*100));
    }
 } 
