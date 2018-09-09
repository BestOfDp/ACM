#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int t,m,n,k,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        k=0;m=1;s=n;
        while(n%2==0)
        {
            n/=2;
            k++;
            m=m*2;
        }
        printf("%d %d\n",s/m,k);
    }
    return 0;
}
