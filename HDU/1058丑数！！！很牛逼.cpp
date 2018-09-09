#include<stdio.h>
#include<string.h>
int  min(int a,int b,int c,int d)
{   int x=a<b?a:b;
        x=x<c?x:c;
        x=x<d?x:d;
        return x;
}
int f[5845];
int main()
{   
    int i,a,b,c,d;
    int n;
    a=b=c=d=1;
    memset(f,0,sizeof(f));
    f[1]=1;
    for(i=2;i<=5843;i++)
    {
        f[i]=min(f[a]*2,f[b]*3,f[c]*5,f[d]*7);
        if(f[i]==f[a]*2)
            a++;
       if(f[i]==f[b]*3)
            b++;
        if(f[i]==f[c]*5)
            c++;
        if(f[i]==f[d]*7)
            d++;

    }

       

       while((scanf("%d",&n)!=EOF)&&n)
       {   if((n%100==11)||(n%100==12)||(n%100==13))
               printf("The %dth humble number is %d.\n",n,f[n]);
              else if(n%10==1)
                printf("The %dst humble number is %d.\n",n,f[n]);
              else if(n%10==2)
                  printf("The %dnd humble number is %d.\n",n,f[n]);
              else if(n%10==3)
                    printf("The %drd humble number is %d.\n",n,f[n]);
              else   printf("The %dth humble number is %d.\n",n,f[n]);
       }


    return 0;

}
