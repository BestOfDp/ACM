#include<stdio.h>
#include<math.h>
int main()
{
	double x1,x2,y1,y2;
	double p;
	while(scanf("%lf%lf%lf%lf",&x1,&x2,&y1,&y2) != EOF)
	{
		p = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
		printf("%.2f\n",p);
	}
 } 
