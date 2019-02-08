#include <stdio.h>
struct pro{
    double x;
    double y;
    double z;
}a[105],t;
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF&&n>=0)
    {
        for ( i = 0 ; i < n ; i++)
        {
            scanf("%lf %lf",&a[i].x,&a[i].y);
            a[i].z = a[i].x / a[i].y;
        }
        for ( i = 0 ; i < n-1 ; i++)
        {
            for ( j = 0 ; j < n-1-i ; j++)
            {
                if (a[j].z < a[j+1].z)
                {
                    t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
            }
        }
        for ( i = 0 ; i < n ; i++)
        {
            printf("%.1lf %.1lf",a[i].x,a[i].y);
            if ( i < n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
