 #include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int mat[10][10];

int ans = 0;
//int can(int num,int y)
//{
//	for(int i=0;i<10;i++)
//	{
//		if(mat[num][i]==1)
//		{
//			return 0;
//		}
//	} 
//	for(int i=0;i<10;i++)
//	{
//		if(mat[i][y]==1) return 0;
//	}
//	int cha = abs(num-y);
//	for(int i=0;i<10;i++)
//	{
//		for(int j=0;j<10;j++)
//		{
//			if(abs(i-num)==abs(j-y) && mat[i][j]==1) return 0;
//		}
//	}
//	return 1;
//}

bool check(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        //����ͬ��
        if(mat[i][col])
        {
            return false;
        }
        //������ͬһ�Խ���
        for(int j=0;j<8;j++)
        {
            if(mat[i][j])
            {
                if( fabs(i - row) - fabs(j - col) == 0)
                {
                    return 0;
                }
            }
        }
    }
    return true;
}

void dfs(int row)
{
    if(row>=8)
    {
        ans++;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for(int col=0;col<8;col++)
    {
    	if(check(row,col))
        {
            mat[row][col] = 1;
            dfs(row + 1);
            mat[row][col] = 0;
        }
    }
}
int main()
{
    memset(mat,0,sizeof(mat));

    dfs(0);

    printf("total = %d\n",ans);
    return 0;
}  
