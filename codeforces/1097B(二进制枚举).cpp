#include <bits/stdc++.h>
using namespace std;
int a[18];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i = 0; i < (1<<n); i++) //从0～2^n-1个状态
    {
    	int ans = 0;
        for(int j = 0; j < n; j++) //遍历二进制的每一位
        {
        	ans = (ans+360)%360;
            if(i & (1 << j))//判断二进制第j位是否存在
            {
                ans += a[j];
            }else{
            	ans -= a[j];
			}
        }
        if(ans==0){
        	cout << "YES" << endl;
        	return 0;
		}
    }
    cout << "NO" << endl;
}
