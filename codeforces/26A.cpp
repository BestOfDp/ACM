#include<bits/stdc++.h> 
using namespace std;

bool is[10000005];
__int64 pri[100005];
void prime()  
{  
    memset(is,0,sizeof(is));  
    int cot=0;  
    for(__int64 i=2;i<=10000000;i++)  
    {  
        if(is[i]==false)  
        {
            {  
                if(cot>=100000)  
                    break;  
                pri[++cot]=i;  
                for(__int64 j=i;j<=10000000;j=j+i)  
                {  
                    is[j]=true;  
                }  
            }  
        }
    }  
} 
int na[30];
int main()
{
	prime();
	int n;
	cin >> n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		int k=i;
		for(int j=1;j<=431;j++)
		{
			if(pri[j] > k ) break;
			if(k%pri[j]==0)
			{
				while(k%pri[j]==0)
				{
					k/=pri[j];
				}
				sum++;
			}
			if(sum>2)
			{
				break;
			}
		}
		if(sum==2 && k==1) cnt++; 
	}
	cout << cnt << endl;
}
